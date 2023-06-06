#ifndef _MUDUOWK_NET_EVENTLOOP_THREAD_
#define _MUDUOWK_NET_EVENTLOOP_THREAD_
#include <functional>
#include <string>

#include "/home/ywk/muduoWK/base/uncopyable.h"
#include "/home/ywk/muduoWK/base/Thread.h"
#include "/home/ywk/muduoWK/base/Mutex.h"
#include "/home/ywk/muduoWK/base/Condition.h"
#include "EventLoop.h"

namespace muduoWK{

namespace net{

class EventLoopThread:uncopyable{
public:
typedef std::function<void()> ThreadInitCallBack;

	EventLoopThread(const ThreadInitCallBack &cb,const std::string &name);
	~EventLoopThread();

	EventLoop* start();//暴露给pool的接口

private:
	void threadFunc();//绑定子线程的启动函数

	EventLoop* loop_;//临时变量，只在loop在子线程运行过程中不为NULL
	Thread thread_;
	Mutex mutex_;
	Condition cond_;
	ThreadInitCallBack cb_;
};


}





}



#endif