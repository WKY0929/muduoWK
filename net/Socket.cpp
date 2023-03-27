#include<iostream>
#include"Log.h"
#include "Socket.h"
using namespace muduo;
using namespace muduo::Sockets;

// #include <stdio.h>
// using namespace muduo
// using namespace muduo::net
// Socket::~Socket()
// {
//     sockets::close(sockfd_);
    
// }
// int main()
// {
//     Socket socket_(1);
//     std::cout<<"haogezhenshuai "<<std::endl;
//     return 0;

// }
int Socket::createNonBlockSocket(sa_family_t family)
{
    int sockfd =::socket(family,SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC,IPPROTO_TCP);//
    if(sockfd<0)
    {
        LOG_FATAL("")//添加log打印信息
    }
    return sockfd;
}
int Socket::connect(int sockfd,const struct sockaddr*  addr)
{
    return ::connect(sockfd,static_cast<socklen_t>(sizeof(struct sockaddr_in)));
}
void Socket::close(int sockfd)
{
    if(::close(sockfd)<0)
    {
        //log
    }
}




