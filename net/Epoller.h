#ifndef MUDUO_EPOLLER_H
#define MUDUO_EPOLLER_H
#include<sys/epoll.h>
#include<unistd.h>

class Epoller{
public:
    explicit Epoller(int maxEvent=1024);
    bool addFd(int fd,uint32_t events);
    bool modFd(int fd,uint32_t events);
    bool delFd(int fd);
    int wait(int timewait=-1);
    ~Epoller();
private:
    int epollerfd_;


};


#endif