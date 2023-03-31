#ifndef MUDUO_NET_SOCKET_H
#define MUDUO_NET_SOCKET_H
#include<iostream>
#include<arpa/inet.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>

// #include<bits/socket.h>
// #include"muduoWK/base/nocopyable.h"

// namespace muduo
// {
// namespace Sockets
// {
class Socket//:noncopyable
{
public:
    explicit Socket(int port):port_(port){
        struct sockaddr_in addr;
        addr.sin_port=htons(port_);
        addr.sin_addr.s_addr=htonl(INADDR_ANY);
        addr.sin_family=AF_INET;
        sockfd_ =socket(AF_INET,SOCK_STREAM,0);
        //设置地址复用
        int optval=1;
        int ret=setsockopt(sockfd_,SOL_SOCKET,SO_REUSEADDR,(const void*)&optval,sizeof(int));
        //设置端口复用
        ret =setsockopt(sockfd_,SOL_SOCKET,SO_REUSEPORT,(const void*)&optval,sizeof(int));

        ret=bind(sockfd_,(struct sockaddr*)&addr,sizeof(addr));
        // ret=listen(sockfd_,5);
        ret=listen(sockfd_,5);
        // struct sockaddr_in client;
        // socklen_t len=sizeof(client);
        // int cfd=accept(sockfd_,(struct sockaddr*)&client,&len);

        // ret=SetNonBlock(sockfd_);
    }
    const int getFd()
    {
        return sockfd_;
    }
    // void start();
    // {
        
    //     // int ret=listen(sockfd_,5);
    //     // struct sockaddr_in client;
    //     // socklen_t len=sizeof(client);
    //     // int cfd=accept(sockfd_,(struct sockaddr*)&client,&len);
    //     // printf("new client is coming\n");
    //     // char ip[16]="";
    //     // inet_ntop(AF_INET,&client.sin_addr.s_addr,ip,16);
    //     // printf("ip address:%s,ip port:%d\n",ip,ntohs(client.sin_port));
    //     // write(cfd,"welcome connect to our server",30);
    //     // sockchat(cfd);
    // }
    int SetNonBlock(int fd);
    ~Socket()
    {
        close(sockfd_);
    }
    void sockchat(int fd);
   

    // int createNonBlockSocket(sa_family_t family);
    // int connect(int socket,const struct sockaddr* addr);
    // void close(int sockfd);

    // ~Socket();
    // void listen();
    // void bindAddress(const InetAddress& localaddr);
    
private:
    int sockfd_;
    int port_;
};



// } 

// }


#endif
