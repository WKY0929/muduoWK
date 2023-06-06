#ifndef _MUDUOWK_NET_TCPSERVER_
#define _MUDUOWK_NET_TCOSERVER_

#include <functional>
#include <memory>
#include <map>
#include <string>
#include <atomic>

#include "/home/ywk/muduoWK/base/uncopyable.h"
#include "/home/ywk/muduoWK/net/EventLoop.h"
#include "/home/ywk/muduoWK/net/EventLoopThreadPool.h"
#include "Connection.h"
#include "Acceptor.h"
#include "Buffer.h"

namespace muduoWK{

namespace net{

class TcpServer:uncopyable{
public:
	typedef std::shared_ptr<Connection> ConnectionPtr;
	typedef std::map<std::string,ConnectionPtr> ConnectionMap;
	typedef std::function<void()> ThreadInitCallBack;
	typedef std::function< void(const std::shared_ptr<Connection>&) > ConnectEstablishedCallBack;
	typedef std::function< void(const std::shared_ptr<Connection>&, Buffer*, TimeStamp) > MessageReceivedCallBack;
	typedef std::function< void(const std::shared_ptr<Connection>&) > MessageSendCallBack;
	typedef std::function< void(const std::shared_ptr<Connection>&) > ConnectDestroyCallBack;
	

	TcpServer(EventLoop* baseLoop,int port,int threadNum,const std::string name ="TcpServer",bool timerWheel=false);
	//~TcpServer();

	void start(); //启动acceptor 在loop中listen

	//定时器接口

	//回调设置
	void setThreadInitCallBack(const ThreadInitCallBack &cb){threadInitCallBack_=cb;}
	void setConnectEstablishedCallBack(const ConnectEstablishedCallBack &cb){connectEstablishedCallBack_=cb;}
	void setMessageReceivedCallBack(const MessageReceivedCallBack &cb){messageReceivedCallBack_=cb;}
	void setMessageSendCallBack(const MessageSendCallBack &cb){messageSendCallBack_=cb;}
	void setConnectDestroyCallBack(const ConnectDestroyCallBack &cb){connectDestroyCallBack_=cb;}

	//test
	size_t getMapSize() const {return connectionMap_.size();}

private:
	void newConnection(int sockfd, const sockaddr &addr);//acceptor调用
	void connectionClose(const ConnectionPtr &connection);//Connection调用
	void connectionCloseInLoop(const ConnectionPtr &connection);
	void defaultThreadInitCallBack();

	EventLoop* baseLoop_;
	Acceptor acceptor_;
	EventLoopThreadPool threadPool_;
	ConnectionMap connectionMap_;

	size_t connectionId_;
	
	std::string port_;
	std::string name_;

	ThreadInitCallBack threadInitCallBack_;//用户
	ConnectEstablishedCallBack connectEstablishedCallBack_;//用户
	MessageReceivedCallBack messageReceivedCallBack_;//用户
	MessageSendCallBack messageSendCallBack_;//用户
	ConnectDestroyCallBack connectDestroyCallBack_;//用户
};





}



}




#endif