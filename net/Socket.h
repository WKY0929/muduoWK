#ifndef MUDUO_NET_SOCKET_H
#define MUDUO_NET_SOCKET_H

#include"muduoWK/base/nocopyable.h"

class Socket:noncopyable
{
public:
    explicit Socket(int sockfd):sockfd_(sockfd){}
    ~Socket();
    void listen();
    void bindAddress(const InetAddress& localaddr);
    
private:
    const int sockfd_;
}

#endif
