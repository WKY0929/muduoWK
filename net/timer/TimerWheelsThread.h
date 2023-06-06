#ifndef _MUDUOWK_NET_TIMERWHEELS_THREAD_
#define _MUDUOWK_NET_TIMERWHEELS_THREAD_

#include "/home/ywk/muduoWK/base/uncopyable.h"
#include "/home/ywk/muduoWK/base/Thread.h"
#include "/home/ywk/muduoWK/base/Mutex.h"
#include "/home/ywk/muduoWK/base/Condition.h"
#include "TimerWheel.h"

namespace muduoWK{

namespace net{

class TimerWheelsThread:uncopyable{
public:
	TimerWheelsThread();
	~TimerWheelsThread();

	TimerWheels* start();

private:
	void threadFunc();//绑定子线程的启动函数

	TimerWheels* timerWheels_;
	Mutex mutex_;
	Condition cond_;
	Thread thread_;
	

};



}



}



#endif