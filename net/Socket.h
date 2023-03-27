#ifndef MUDUO_NET_SOCKET_H
#define MUDUO_NET_SOCKET_H
#include<sys/types.h>
#include<unistd.h>
#include<sys/socket.h>
// #include"muduoWK/base/nocopyable.h"

namespace muduo
{
namespace Sockets
{
class Socket//:noncopyable
{
public:
    explicit Socket(int sockfd):sockfd_(sockfd){}
    int createNonBlockSocket(sa_family_t family);
    int connect(int socket,const struct sockaddr* addr);
    void close(int sockfd);

    // ~Socket();
    // void listen();
    // void bindAddress(const InetAddress& localaddr);
    
private:
    const int sockfd_;
};



} 

}


#endif
