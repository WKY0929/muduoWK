//#include"Log.h"
#include "Socket.h"
// using namespace muduo;
// using namespace muduo::Sockets;

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
// int Socket::createNonBlockSocket(sa_family_t family)
// {
//     int sockfd =::socket(family,SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC,IPPROTO_TCP);//
//     if(sockfd<0)
//     {
//         //LOG_FATAL("")//添加log打印信息
//     }
//     return sockfd;
// }
// int Socket::connect(int sockfd,const struct sockaddr*  addr)
// {
//     return ::connect(sockfd,addr,static_cast<socklen_t>(sizeof(struct sockaddr_in)));
// }
// void Socket::close(int sockfd)
// {
//     if(::close(sockfd)<0)
//     {
//         //log
//     }
// }
int Socket::SetNonBlock(int fd)
{
    int old_option=fcntl(fd,F_GETFL);
    int new_option=old_option | O_NONBLOCK;
    fcntl(fd,F_SETFL,new_option);
    return old_option;

}
 void Socket::sockchat(int fd)
    {
        pid_t pid=fork();
        if(0==pid)
        {
            while(1)
            {
        
                char buf1[1024]="";
                // write(fd,"hello",5);
                read(fd,buf1,sizeof(buf1));
                printf("client:%s",buf1);
            }
        }else
        {
            while(1)
            {
                char buf2[1024]="";
                int n=read(STDIN_FILENO,buf2,sizeof(buf2));
                write(fd,buf2,n);
            }
        }

    }




