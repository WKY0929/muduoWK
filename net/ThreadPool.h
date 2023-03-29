#ifndef MUDUO_NET_THREADPOOL_H
#define MUDUO_NET_THREADPOOL_H
#include<thread>


class ThreadPool
{
public:
    explicit ThreadPool(size_t threadNum):stop_(false)
    {

    }
private:
    bool stop_;

};

#endif