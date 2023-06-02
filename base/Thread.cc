#include<assert.h>
#include "Thread.h"
#include"CurrentThread.h"

namespace muduoWK{

void* Thread::startThread(void* obj){
    ThreadData* tData =static_cast<ThreadData*>(obj);
    tData->run();
    delete tData;
    return NULL;
}


Thread::Thread(const Function &func,const std::string &name)
    :func_(func),name_(name),running_(false),joined_(false),latch_(1),pthreadId_(0),tid_(0){}

Thread::~Thread(){
    if(running_&&!joined_)pthread_detach(pthreadId_);}
void Thread::start()
{
    assert(!running_);
    running_=true;
    ThreadData* tData=new ThreadData(func_,name_,&tid_,&latch_);
    if(pthread_create(&pthreadId_,NULL,Thread::startThread,tData)){
        delete tData;
        running_=false;
    }else{
        latch_.wait();
        assert(tid_>0);
    }
}
int Thread::join(){
    assert(running_);
    assert(!joined_);
    joined_=true;
    return pthread_join(pthreadId_,NULL);
}
ThreadData::ThreadData(const Function &func,const std::string name,pid_t* tid,CountDownLatch* latchA)
    :func_(func),name_(name),tid_(tid),latch_(latchA){}
void ThreadData::run()
{
    *tid_= CurrentThread::tid();
    tid_ = NULL;
    CurrentThread::t_threadName = name_.empty() ? "Thread" : name_.c_str();
    prctl(PR_SET_NAME, CurrentThread::t_threadName);

    latch_->countDown();
    latch_ = NULL;
    func_();
    
    CurrentThread::t_threadName = "finished";
}

}

