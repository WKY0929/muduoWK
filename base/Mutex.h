#ifndef _MUDUOWK_BASE_MUTEX_
#define _MUDUOWK_BASE_MUTEX_

#include<pthread.h>
#include "uncopyable.h"

namespace muduoWK{

class Mutex:uncopyable{
public:
    Mutex(){
        pthread_mutex_init(&mutex_,NULL);}
        ~Mutex(){
            pthread_mutex_lock(&mutex_);
            pthread_mutex_destroy(&mutex_);
        }
    void lock(){ pthread_mutex_lock(&mutex_); }
    void unlock(){ pthread_mutex_unlock(&mutex_); }
    pthread_mutex_t *getMutex(){return &mutex_;}
private:
    pthread_mutex_t mutex_;
friend class Condition;
//声明友元，使得Condition类可以访问Mutex的所有成员
};
//自动绑定并加锁，在析构函数中解锁
class MutexLockGuard:uncopyable{
public:
    //显式构造，不允许隐式转换
    explicit  MutexLockGuard(Mutex &mutexA):mutex(mutexA){mutex.lock();}
    ~MutexLockGuard(){mutex.unlock();}

private:
    //用引用类型的mutex即可
    Mutex &mutex;

};
}
#endif