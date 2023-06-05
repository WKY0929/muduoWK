#ifndef _MUDUOWK_NET_EVENTLOOP_
#define _MUDUOWK_NET_EVENTLOOP_

#include<vector>
#include<memory>
#include<functional>

#include "/home/ywk/muduoWK/base/uncopyable.h"
#include "/home/ywk/muduoWK/base/TimeStamp.h"
#include "/home/ywk/muduoWK/base/Mutex.h"
#include "/home/ywk/muduoWK/net/timer/TimerWheel.h"
#include"/home/ywk/muduoWK/net/timer/Timer.h"

namespace muduoWK{

namespace net{

class Epoller;
class Channel;
class Socket;

class EventLoop:uncopyable{

public:
    typedef std::function<void()> Function;
    typedef std::shared_ptr<Timer>TimerPtr;
    typedef std::function<void()> TimerReachFunction;
	EventLoop();
	~EventLoop();

    EventLoop* getEventLoopOfCurrentThread() const ;
    void loop();
	void quitLoop();
	void runInLoop(Function function);
	void queueInLoop(Function function);
	void assertInLoopThread();
	bool isInLoopThread();
	void doPendingFunctions();
    //定时任务

	//wakeupchannel唤醒
	void wakeup();

	//epollfd:由channel调用，令epoll对底层更新
	void updateChannel(Channel* channel);
};



}




}


#endif