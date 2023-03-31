#include "Epoller.h"

Epoller::Epoller(int maxEvent):epollerfd_(epoll_create(512)){}

Epoller::~Epoller()
{
    close(epollerfd_);
}

bool Epoller::addFd(int fd,uint32_t events)
{
    epoll_event event;
    event.data.fd=fd;
    event.events=events;
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


