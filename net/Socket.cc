#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<sys/uio.h>
#include<netinet/tcp.h>

#include"Socket.h"

namespace muduoWK{

namespace net{

int Socket::createNonblockSocket(){
    int fd=::socket(AF_INET,SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC,IPPROTO_TCP);
        return fd;
}
bool Socket::bind(int port){
    if(port<0 ||port>65535)return false;
    struct sockaddr_in sock_addr;
    bzero((char*)&sock_addr,sizeof(sock_addr));
    sock_addr.sin_family=AF_INET;
    sock_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    sock_addr.sin_port=htons((unsigned short)port);
    if(::bind(fd_,(struct sockaddr*)&sock_addr,sizeof(sock_addr)==-1)){
        close();
        return false;
    }
    return true;

}

bool Socket::connect(int port,const char* ip){
	if (port < 0 || port > 65535) return false;

	struct sockaddr_in sock_addr;
	bzero((char *)&sock_addr, sizeof(sock_addr));
	sock_addr.sin_family = AF_INET; //地址族
	sock_addr.sin_addr.s_addr  = inet_addr(ip);
	sock_addr.sin_port  = htons((unsigned short)port); //端口号

	if(::connect(fd_,(struct sockaddr *)&sock_addr,sizeof(sockaddr)) == -1){
		close();
		return false;
	}
	return true;
}
bool Socket::listen(){
	if(::listen(fd_,128)==-1){
		close();
		return false;
	}
	return true;
}
int Socket::accept(){
    struct sockaddr addr;
    socklen_t addrlen=static_cast<socklen_t>(sizeof(addr));
    bzero((char*)&addr,sizeof(addr));
    int connfd=::accept(fd_,&addr,&addrlen);
    return connfd;
}
int Socket::accept(int &conFd,sockaddr &addr){
	socklen_t addrlen = static_cast<socklen_t>(sizeof(addr));
  	bzero((char *)&addr, sizeof(addr));
	int connfd = ::accept(fd_,&addr,&addrlen);
	if(connfd >= 0) {
		conFd = connfd;
		return connfd;
	}
	return -1;
}
ssize_t Socket::read(void *buf, size_t count){
	return ::read(fd_, buf, count);
}

ssize_t Socket::readv(int sockfd, const struct iovec *iov, int iovcnt){
  return ::readv(sockfd, iov, iovcnt);
}

ssize_t Socket::write(const char*buf, size_t count){
	return ::write(fd_, buf, count);
}

bool Socket::close(){
	if(::close(fd_)==-1) return false;
	return true;
}

bool Socket::shutdownWrite(){
	if (::shutdown(fd_, SHUT_WR) < 0) return false;
	return true;
}
bool Socket::setReuseAddr(){
	int on = 1;
	if(::setsockopt(fd_, SOL_SOCKET, SO_REUSEADDR, &on, static_cast<socklen_t>(sizeof on)) < 0) return false;
	return true;
	
}
bool Socket::setReusePort(){
	int on = 1;
	if(::setsockopt(fd_, SOL_SOCKET, SO_REUSEPORT, &on, static_cast<socklen_t>(sizeof on)) < 0) return false;
	return true;
}
bool Socket::setKeepAlive()
{
  	int on = 1;
 	if( ::setsockopt(fd_, SOL_SOCKET, SO_KEEPALIVE, &on, static_cast<socklen_t>(sizeof on)) < 0) return false;
	return true;
}

bool Socket::setNoDelay(){
	int on = 1;
 	if( ::setsockopt(fd_, IPPROTO_TCP, TCP_NODELAY, &on, static_cast<socklen_t>(sizeof on)) < 0) return false;
	return true;
}


}


}