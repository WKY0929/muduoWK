#ifndef _MUDUOWK_NET_ACCEPTOR_
#define _MUDUOWK_NET_ACCEPTOR_
#include <functional>
#include <sys/socket.h>

#include "/home/ywk/muduoWK/net/Socket.h"
#include "/home/ywk/muduoWK/net/Channel.h"
#include "/home/ywk/muduoWK/net/EventLoop.h"
#include "/home/ywk/muduoWK/base/uncopyable.h"

namespace muduoWK{

namespace net{

class Acceptor:uncopyable{
public:
	typedef std::function<void (int sockfd, const sockaddr &addr)> NewConnectionCallBack;

	Acceptor(EventLoop* loop,int port);
	~Acceptor();

	int listen();//失败返回-1

	void setNewConnectionCallBack(const NewConnectionCallBack &func){newConCallBackFunc_ = func; }

private:
	void handleRead();//channel的callback

	EventLoop* loop_;
	Socket acceptorSocket_;
	Channel acceptChannel_;
	NewConnectionCallBack newConCallBackFunc_;
	int idleFd_;//为避免fd耗尽的方案：用此fd接收连接后立刻关闭

};




}




}






#endif