#ifndef _MUDUOWK_BASE_THREAD_
#define _MUDUOWK_BASE_THREAD_

#include<string>
#include<functional>
#include<pthread.h>

#include "uncopyable.h"
#include "CountDownLatch.h"
 
typedef std::function<void()> Function;
namespace muduoWK{

class Thread:uncopyable{
public:
    explicit Thread(const Function &func,const std::string & name=std::string("Thread"));
    ~Thread();

    void start();
    int join();
    static void* startThread(void* obj);
    bool running()const {return running_;}
    const std::string& name()const {return name_;}
private:
    Function func_;
    std::string name_;
    bool running_;
    bool joined_;
    CountDownLatch latch_;
    pthread_t pthreadId_;
    pid_t tid_;
};

struct ThreadData{
    Function func_;
    std::string name_;
    pid_t* tid_;
    CountDownLatch* latch_;

    ThreadData(const Function &func,const std::string name,pid_t* tid,CountDownLatch* latchA);
    void run();
};


}
#endif