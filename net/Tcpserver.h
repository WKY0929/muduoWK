#ifndef MUDUO_TCPSERVER_H
#define MUDUO_TCPSERVER_H
#include<string>
#include<vector>
#include<map>
//#include<atomic>
#include<memory>
#include "Epoller.h"
#include "Socket.h" 
class Tcpserver
{
public:
    Tcpserver(int port);
    void start();

private:
    void startThreadPool();
private:
    //EventLoop* pMainLoop; //TcpServer所在主线程的EventLoop
    //InetAddress listenAddress_;//Server监听地址
    Socket ServerSocket_;
    // const std::string name_; //
    //AtomicInt32 started_;  //
    // const int numEventThreads_;//
    
    //std::vector<std:::uniqe_ptr<ServerThread>>serverThreadVect_;
    //std::vector<EventLoop*>ServerLoopVect_;
    //std::unique_ptr<ListenSocket>listenSocket_;
    //typedef std::map<std::string,TcpLinkSPtr>TcpLinkMap;
    // int nextLinkId_;
    // TcpLinkMap tcpLinkMap_;

};

#endif