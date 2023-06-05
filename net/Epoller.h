
#ifndef _MUDUOWK_NET_EPOLLER_
#define _MUDUOWK_NET_EPOLLER_

#include <sys/epoll.h>
#include <vector>

#include "/home/ywk/muduoWK/base/uncopyable.h"
#include "/home/ywk/muduoWK/base/TimeStamp.h"

namespace muduoWK{

namespace net{

class EventLoop;
class Channel;
class Epoller:uncopyable{
public:
    typedef std::vector<Channel*>Channels;
    explicit Epoller(EventLoop* loop);
    ~Epoller();
    TimeStamp poll(int timeout,Channels& activeChannels);//返回时间戳,timeout阻塞时间，由loop传入
    void updateChannel(Channel* channel);//给loop的接口，更新底层epollfd
    static const int InitEventsSize;//events_的初始大小
private:
    EventLoop* eventLoop_;
    int epollFd_;
    std::vector<struct epoll_event> events_;


};


}



}

#endif