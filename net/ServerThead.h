#ifndef MUDUO_SERVER_THREAD_H
#define MUDUO_SERVER_THREAD_H
#include<>

class ServerThread
{
public:
    ServerThread();
    ~ServerThread();
    EventLoop* startThread();
private:
    
};


#endif