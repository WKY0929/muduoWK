#include "HTTPconnection.h"

HTTPconnection::HTTPconnection()
{
    fd_=-1;
    addr_={0};
    isClose_=true;

}
void HTTPconnection::initHTTPConn(int fd,const sockaddr_in& addr)
{
    userCount++;
    addr_=addr;
    fd_=fd;
    writeBuffer_.initPtr();
    readBuffer_.initPtr();
    isClose_=false;
}
