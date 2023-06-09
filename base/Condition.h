#ifndef _MUDUOWK_BASE_CONDITION_
#define _MUDUOWK_BASE_CONDITION_

#include<errno.h>
#include<time.h>
#include<pthread.h>

#include "uncopyable.h"
#include "Mutex.h"

namespace muduoWK{

class Condition:uncopyable{
public:
    explicit Condition(Mutex& mutexA):mutex(mutexA){pthread_cond_init(&cond_,NULL);}
    ~Condition(){pthread_cond_destroy(&cond_);}
    void wait(){ pthread_cond_wait(&cond_, mutex.getMutex());}

    void notifyOne(){pthread_cond_signal(&cond_);}

    void notifyAll(){pthread_cond_broadcast(&cond_);}
    
    bool waitForSeconds(int second){
        struct timespec abstime;
        clock_gettime(CLOCK_REALTIME,&abstime);
        abstime.tv_sec+=static_cast<time_t>(second);
        return ETIMEDOUT == pthread_cond_timedwait(&cond_,mutex.getMutex(),&abstime);
    }
private:
    pthread_cond_t cond_;
    Mutex &mutex;
};

}

#endif

