#ifndef MUDUO_EPOLLER_H
#define MUDUO_EPOLLER_H
#include<sys/epoll.h>
#include<unistd.h>
#include<vector>
#include<assert.h>
class Epoller{
public:
    explicit Epoller(int maxEvent=10);
    bool addFd(int fd,uint32_t events,bool enable_et);
    bool modFd(int fd,uint32_t events);
    bool delFd(int fd);
    int geteventFd(int i);
    int wait(int timewait=-1);
    uint32_t getevent(int i);
    ~Epoller();
private:
    int epollerfd_;
    std::vector<struct epoll_event>_events;
    const int MaxEvents=10;
};


#endif