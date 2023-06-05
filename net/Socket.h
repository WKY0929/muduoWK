#ifndef _MUDUOWK_NET_SOCKET_
#define _MUDUOWK_NET_SOCKET_
#include <sys/socket.h>
#include <unistd.h>
#include<fcntl.h>

#include"/home/ywk/muduoWK/base/uncopyable.h"

namespace muduoWK{

namespace net{

class Socket:uncopyable{
public:
    explicit Socket(int sockfd):fd_(sockfd){
        fcntl(sockfd,F_SETFL,O_NONBLOCK);
    }
    ~Socket(){::close(fd_);}
    int getFd()const {return fd_;}
    static int createNonblockSocket();
	bool bind(int port);//成功返回true,绑定在任何ip
	bool connect(int port,const char* ip);
	bool listen();
	int accept();//返回fd，失败返回-1
	int accept(int &conFd,sockaddr &addr); //传入addr，传出fd
	ssize_t read(void *buf, size_t count);//成功返回读出的字节数，出错返回-1并设置errno
	ssize_t readv(int sockfd, const struct iovec *iov, int iovcnt);
	ssize_t write(const char *buf, size_t count);//成功返回写入的字节数，出错返回-1并设置errno

    bool close();
    bool shutdownWrite();
    bool setReuseAddr();
    bool setReusePort();
    bool setKeepAlive();
    bool setNoDelay();
private:
    const int fd_;


};

}

}


#endif