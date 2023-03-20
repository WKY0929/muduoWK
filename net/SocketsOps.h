#ifndef MUDUO_NET_SOCKETSOPS_H
#define MUDUO_NET_SOCKETSOPS_H

#include <arpa/inet.h>

namespace muduo
{
namespace net
{
namespace sockets
{
    int connet(int sockfd,const struct sockaddr* addr);
    int accept(int sockfd,const struct sockaddr* addr);
}//namespace sockets
    
} // namespace net

}//namespace muduo

#endif