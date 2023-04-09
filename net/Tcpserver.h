#ifndef MUDUO_TCPSERVER_H
#define MUDUO_TCPSERVER_H
#include<string>
#include<vector>
#include<map>
#include<algorithm>
//#include<atomic>
#include<memory>
#include<pthread.h>
#include<string.h>
#include<functional>
#include "Epoller.h"
#include "Socket.h" 
#include "ThreadPool.h"
class Tcpserver
{
public:
    Tcpserver(int port,size_t threadNum=2);
    void start();

private:
    // void startThreadPool();
    void closeConn_();
    void handleRead_(int fd);
    void handleWrite_(int fd);
    void lt(int eventCnt);
    void et(int eventCnt);
private:
    //EventLoop* pMainLoop; //TcpServer所在主线程的EventLoop
    //InetAddress listenAddress_;//Server监听地址
    Socket ServerSocket_;
    Epoller ServerEpoll_;
    // pthread_t thread1;
    std::unique_ptr<ThreadPool> threadpool_;
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