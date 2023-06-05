#include <sys/eventfd.h>

#include "/home/ywk/muduoWK/base/Logger.h"
#include "/home/ywk/muduoWK/base/CurrentThread.cc"
#include "EventLoop.h"
#include "Epoller.h"
#include "Socket.h"
#include "Channel.h"


bool EventLoop::isInLoopThread(){
	return threadId_ == CurrentThread::tid();
}