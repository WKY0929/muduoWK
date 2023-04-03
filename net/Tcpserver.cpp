#include "Tcpserver.h"


//Tcpserver::Tcpserver
Tcpserver::Tcpserver(int port):ServerSocket_(port)
{
    int Serverfd_=ServerSocket_.getFd();
    ServerSocket_.SetNonBlock(Serverfd_);
    ServerEpoll_.addFd(Serverfd_,EPOLLRDHUP | EPOLLIN);
    printf("init is over\n");

}

void Tcpserver::start()
{
    //ServerSocket_.sockchat();
    while(1)
    {
        int eventCnt=ServerEpoll_.wait(-1);
        for(int i=0;i<eventCnt;i++)
        {
            int fd=ServerEpoll_.geteventFd(i);
            uint32_t events=ServerEpoll_.getevent(i);
            if(fd==ServerSocket_.getFd())
            {
                struct sockaddr_in client_address;
                socklen_t len=sizeof(client_address);
                int connfd=accept(fd,(struct sockaddr*)&client_address,&len);
                //char buf[1024]={""};
                ServerEpoll_.addFd(connfd,EPOLLIN);
                // char ip[16]="";
                // inet_ntop(AF_INET,&client_address,ip,16);
                // printf("new connect: ip %s,port %d \n",ip,ntohs(client_address.sin_port));
                

                write(connfd,"welcome to my server",21);
            }else if(events & (EPOLLRDHUP | EPOLLHUP | EPOLLERR))
            {
                
            }
            else if(events & EPOLLIN)
            {

            }else if(events & EPOLLOUT)
            {

            }
        }
    }
    
}
