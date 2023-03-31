#include "ServerThread.h"

EventLoop*ServerThead::startThrad()
{
    start_=true;
    if(pthread_create(&pthreadId_,NULL,&threadEntry,this))
    {
        start_=false;
    }
    MutexLocking lock(mutex_);
    while (pEventLoop_==NULL)
    {
        /* code */
        condition_.wait();
    }
    return pEventLoop_;
}
void* ServerThead::threadEntry(void* arg)
{
    ServerThead* pServerThread=(ServerThead*)arg;
    EventLoop tcpServerLoop;
    //TcpServer tcpServer();
    {

    }
    tcpServer.start();
    tcpServer.loop();
    pServerThread->pEventLoop_=NULL;
    return NULL;
}

