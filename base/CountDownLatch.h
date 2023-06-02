#ifndef _MUDUOWK_BASE_COUNTDOWNLATCH_
#define _MUDUOWK_BASE_COUNTDOWNLATCH_

#include "uncopyable.h"
#include "Mutex.h"
#include "Condition.h"

namespace muduoWK{
class CountDownLatch:uncopyable{
public:
    explicit CountDownLatch(int count):mutex_(),cond_(mutex_),count_(count){}

    void wait()
    {
        MutexLockGuard lock(mutex_);
        while(count_>0) cond_.wait();
    }
    void countDown()
    {
        MutexLockGuard lock(mutex_);
        --count_;
        if(count_==0)cond_.notifyAll();
    }
private:
    int count_;
    mutable Mutex mutex_;
    Condition cond_;
};




}

#endif