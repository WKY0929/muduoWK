#ifndef HTTP_CONNECTION_H
#define HTTP_CONNECTION_H
#include<arpa/inet.h>
#include<sys/uio.h>
#include<iostream>


#include "buffer.h"
#include "HTTPrequest.h"

class HTTPconnection{
public:
    HTTPconnection();
    ~HTTPconnection();
    void initHTTPConn(int fd,const sockaddr_in& addr);
    // static bool isET;
    static const char* srcDir;
    static std::atomic<int>userCount;
private:
    int fd_;
    bool isClose_;
    struct sockaddr_in addr_;
    HTTPrequest request_;
    Buffer readBuffer_;
    Buffer writeBuffer_;
};

#endif