#include "Tcpserver.h"


//Tcpserver::Tcpserver
Tcpserver::Tcpserver(int port):ServerSocket_(port)
{

    int Serverfd_=ServerSocket_.getFd();
    ServerSocket_.SetNonBlock(Serverfd_);
    ServerEpoll_.addFd(Serverfd_,EPOLLRDHUP | EPOLLIN,true);
    printf("init is over\n");

}
void Tcpserver::closeConn_()
{
    printf("something else happened\n");
}
void Tcpserver::handleRead_(void* arg)
{
    int* temp=(int*)arg;
    int fd=*temp;
    while(1)
    {
        printf("event trigger once\n");
        char buf[10]="";
        int ret=recv(fd,buf,sizeof buf,0);
        if(ret<0)
        {
            if(errno==EAGAIN || errno ==EWOULDBLOCK)
            {
                printf("read later\n");
                break;
            }
            close(fd);
            break;
        }else if(ret==0)
        {
            close(fd);
        }else
        {
            printf("%s",buf);
            //break;
        }
    }
}
void Tcpserver::lt(int eventCnt)
{
    char buf[10];
    for(int i=0;i<eventCnt;i++)
    {
        int fd=ServerEpoll_.geteventFd(i);
        uint32_t events = ServerEpoll_.getevent(i);
        if(fd==ServerSocket_.getFd())
        {
            int listenfd=ServerSocket_.getFd();
            struct sockaddr_in client;
            socklen_t len=sizeof(client);
            int connfd=accept(listenfd,(struct sockaddr*)&client,&len);
            ServerEpoll_.addFd(connfd,EPOLLIN,false);
            char ip[16]="";
            inet_ntop(AF_INET,&client,ip,16);
            printf("new connect ip:%s,port %d \n",ip,ntohs(client.sin_port));
        }else if(events & EPOLLIN)
        {
            printf("event trigger once\n");
            memset(buf,'\0',10);
            int ret=recv(fd,buf,10-1,0);
            if(ret<=0)
            {
                close(fd);
                continue;
            }
            printf("%s",buf);
        }else 
        {
            printf("something else happened\n");
        }
    }
}
void Tcpserver::et(int eventCnt)
{
    char buf[10];
    for(int i=0;i<eventCnt;i++)
    {
        int fd=ServerEpoll_.geteventFd(i);
        uint32_t events = ServerEpoll_.getevent(i);
        if(fd==ServerSocket_.getFd())
        {
            int listenfd=ServerSocket_.getFd();
            struct sockaddr_in client;
            socklen_t len=sizeof(client);
            int connfd=accept(listenfd,(struct sockaddr*)&client,&len);
            ServerEpoll_.addFd(connfd,EPOLLIN,false);
            char ip[16]="";
            inet_ntop(AF_INET,&client,ip,16);
            printf("new connect ip:%s,port %d \n",ip,ntohs(client.sin_port));
        }else if(events & EPOLLIN)
        {
            // printf("event trigger once\n");
            // while(1)
            // {
            //     memset(buf,'\0',10);
            //     int ret=recv(fd,buf,10-1,0);
            //     if(ret<0)
            //     {
            //         if((errno==EAGAIN)||(errno==EWOULDBLOCK))
            //         {
            //             printf("read later\n");
            //             break;
            //         }
            //         close(fd);
            //         break;
            //     }else if(ret==0)
            //     {
            //         close(fd);
            //     }else{
            //         printf("%s",buf);
            //     }
            // }
            int ret=pthread_create(&thread1,NULL,handleRead_,(void*)fd)
        }
    }
}
void Tcpserver::start()
{
    //ServerSocket_.sockchat();
    while(1)
    {
        int eventCnt=ServerEpoll_.wait(-1);
        if(eventCnt<0)
        {
            printf("epoll failure\n");
            break;
        }
        // lt(eventCnt);

        et(eventCnt);
        // for(int i=0;i<eventCnt;i++)
        // {
        //     int fd=ServerEpoll_.geteventFd(i);
        //     uint32_t events=ServerEpoll_.getevent(i);
        //     if(fd==ServerSocket_.getFd())
        //     {
        //         struct sockaddr_in client_address;
        //         socklen_t len=sizeof(client_address);
        //         int connfd=accept(fd,(struct sockaddr*)&client_address,&len);
        //         //char buf[1024]={""};
        //         ServerEpoll_.addFd(connfd,EPOLLIN,true);
        //         // char ip[16]="";
        //         // inet_ntop(AF_INET,&client_address,ip,16);
        //         // printf("new connect: ip %s,port %d \n",ip,ntohs(client_address.sin_port));
                

        //         write(connfd,"welcome to my server",21);
        //     }else if(events & (EPOLLRDHUP | EPOLLHUP | EPOLLERR))
        //     {
        //         closeConn_();
        //     }
        //     else if(events & EPOLLIN)
        //     {
        //         handleRead_(fd);
        //     }else if(events & EPOLLOUT)
        //     {
        //         printf("have no this function\n");
        //     }
        // }
    }
    
}
