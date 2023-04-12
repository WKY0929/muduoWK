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
private:
    
};

#endif