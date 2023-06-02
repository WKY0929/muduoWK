#ifndef _MUDUOWK_BASE_ASYNCLOGGING_
#define _MUDUOWK_BASE_ASYNCLOGGING_

#include<vector>
#include<string>
#include<memory>

#include "uncopyable.h"
#include "FixedBuffer.h"
#include "Thread.h"
#include "Mutex.h"
#include "Condition.h"
#include "CountDownLatch.h"

namespace muduoWK{

class AsyncLogging:uncopyable{ 
public:
    typedef muduoWK::FixedBuffer<bigBufferSize> Buffer;
    typedef std::unique_ptr<Buffer> BufferPtr;
    typedef std::vector<BufferPtr> BufferVector;

    explicit AsyncLogging(const char* logFileName,size_t rollSize,int interval =3);
    ~AsyncLogging();
    void append(const char* msg,size_t len);
    void start();
    void stop();
    void run();
private:
    BufferPtr bufferCurrent_;
    BufferPtr bufferNext_;
    BufferVector bufferVector_;
    size_t interval_;
    std::string logFileName_;
    Thread thread_;
    Mutex mutex_;
    Condition cond_;
    CountDownLatch latch_;
    bool running_;
    size_t rollSize_;
};

}
#endif