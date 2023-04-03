#include "Epoller.h"

Epoller::Epoller(int maxEvent):epollerfd_(epoll_create(512)),_events(MaxEvents){

}

Epoller::~Epoller()
{
    close(epollerfd_);
}

bool Epoller::addFd(int fd,uint32_t events,bool enable_et)
{
    epoll_event event;
    event.data.fd=fd;
    event.events=events;
    if(enable_et)
    {
        event.events |= EPOLLET;
    }
    int ret=epoll_ctl(epollerfd_,EPOLL_CTL_ADD,fd,&event);
    return ret;
}
bool Epoller::modFd(int fd,uint32_t events)
{
    epoll_event event;
    event.data.fd=fd;
    event.events=events;
    int ret=epoll_ctl(epollerfd_,EPOLL_CTL_MOD,fd,&event);
    return ret;
}
bool Epoller::delFd(int fd)
{
    epoll_event event={0};
    return 0==epoll_ctl(epollerfd_ ,EPOLL_CTL_DEL,fd,
    &event);
}
int Epoller::wait(int timewait)
{
    return epoll_wait(epollerfd_,&_events[0],MaxEvents,timewait);
}

int Epoller::geteventFd(int i)
{
    return _events[i].data.fd;
}

uint32_t Epoller::getevent(int i)
{
    return _events[i].events;
}
