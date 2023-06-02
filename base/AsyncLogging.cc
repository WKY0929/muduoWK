#include "AsyncLogging.h"
#include "logFile.h"

namespace muduoWK{

AsyncLogging::AsyncLogging(const char*logFileName,size_t rollSize,int interval)
    :bufferCurrent_(new Buffer),
    bufferNext_(new Buffer),
    interval_(interval),
    logFileName_(logFileName),
    thread_(std::bind(&AsyncLogging::run,this),"Logging"),
    mutex_(),
    cond_(mutex_),
    latch_(1),
    running_(false),
    rollSize_(rollSize)
{
    bufferCurrent_->bZero();
    bufferNext_->bZero();
    bufferVector_.reserve(16);//分配空间修改尺寸
}

AsyncLogging::~AsyncLogging(){
    stop();
}

void AsyncLogging::start(){
    running_=true;
    thread_.start();
    latch_.wait();
}

void AsyncLogging::stop(){
    running_ = false;
    cond_.notifyAll();
    thread_.join();
}

void AsyncLogging::append(const char* msg,size_t len){
    MutexLockGuard lock(mutex_);
    if(bufferCurrent_->getDataLen()>=static_cast<int>(len)){
        bufferCurrent_->append(msg,len);
    }else{
        bufferVector_.push_back(std::move(bufferCurrent_));
        if(bufferNext_)bufferCurrent_=std::move(bufferNext_);
        else{
            bufferCurrent_.reset(new Buffer);
            bufferCurrent_->resetCur();
        }
        bufferCurrent_->append(msg,len);
    }
    cond_.notifyOne();
}
void AsyncLogging::run(){
    latch_.countDown();
    LogFile output(true,rollSize_,logFileName_);
    BufferPtr bufferBack1(new Buffer);
    BufferPtr bufferBack2(new Buffer);
    bufferBack1->bZero();
    bufferBack2->bZero();
    BufferVector bufferBackVec;
    bufferBackVec.reserve(16);
    while (running_){
        {
            MutexLockGuard lock(mutex_);

            if(bufferVector_.empty())cond_.waitForSeconds(interval_);//超时触发
            bufferBackVec.swap(bufferVector_);
            bufferBackVec.push_back(std::move(bufferCurrent_));
            bufferCurrent_=move(bufferBack1);
            bufferCurrent_->resetCur();
            if(!bufferNext_){
                bufferNext_=move(bufferBack2);
                bufferNext_->resetCur();
            }
        }
        //此时bufferBack1一定空，bufferBack2可能空，需要提交数据到logfile，重置缓存
        if(bufferBackVec.size()>25) bufferBackVec.erase(bufferBackVec.begin() + 2, bufferBackVec.end());//数据太多的时候只保留两个
        
        //因为是uniqueptr，所以不能用for(BufferPtr bp:bufferBackVec)拷贝
        for(int i = 0;i<bufferBackVec.size();++i){
            output.output(bufferBackVec[i]->getData(),bufferBackVec[i]->getDataLen());//输入到后端logfile，实质传的是char*
        }

        if(bufferBackVec.size()>2) bufferBackVec.resize(2);

        if(!bufferBack1){
            bufferBack1 = move(bufferBackVec.back());
            bufferBackVec.pop_back();//只能理解为，bufferBack2里bufferBackVec调用back
            bufferBack1->resetCur();
        }
        
        if(!bufferBack2){
            bufferBack2 = move(bufferBackVec.back());
            bufferBackVec.pop_back();//只能理解为，bufferBack2里bufferBackVec调用back
            bufferBack2->resetCur();
        }
        bufferBackVec.clear();
        output.flush();
    }
    output.flush();
    
}



}