#include "EventLoop.h"
#include "Channel.h"

namespace muduoWK{

namespace net{

const int Channel::CNew=-1;
const int Channel::CAdded=1;
const int Channel::CDeleted=2;

const int Channel::NoneEvent = 0;
const int Channel::ReadEvent = EPOLLIN | EPOLLPRI | EPOLLET;//EPOLLET为边缘触发，默认是水平触发
const int Channel::WriteEvent = EPOLLOUT;

Channel::Channel(EventLoop*loop,int fd)
    :eventLoop_(loop),
    fd_(fd),
    event_(0),
    activeEvent_(0),
    tied_(false),
    state_(CNew){}
Channel::~Channel(){}

void Channel::tie(const std::shared_ptr<void>& obj){
	if(!tied_){
		tie_ = obj;
		tied_ = true;
	}
}

void Channel::handleEvent(TimeStamp receiveTime){
    if(tied_){
        std::shared_ptr<void> guard;
        guard =tie_.lock();
        if(guard){
            handleEventWithoutGuard(receiveTime);
        }
    }else{
        handleEventWithoutGuard(receiveTime);
    }
}

void Channel::handleEventWithoutGuard(TimeStamp receiveTime){
    if((activeEvent_&POLLHUP)&&!(activeEvent_&POLLIN)){
        if(callBackClose_)callBackClose_();
    }
    if(activeEvent_&(POLLERR|POLLNVAL)){
        if(callBackError_)callBackError_();
    }
    if(activeEvent_&(POLLIN | POLLPRI | POLLRDHUP)){
        if(callBackRead_)callBackRead_(receiveTime);
    }
    if(activeEvent_&POLLOUT){
        if(callBackWrite_)callBackWrite_();
    }
}
void Channel::updateChannel(){
	eventLoop_->updateChannel(this);
}


}


}