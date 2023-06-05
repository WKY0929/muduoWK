#include<sys/uio.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>

#include "/home/ywk/muduoWK/base/Logger.h"
#include "Buffer.h"

namespace muduoWK{

namespace net{

Buffer::Buffer(size_t size):buffer_(size),writeIndex_(0),readIndex_(0){}
void Buffer::append(const char* msg,int len){
    if(getWriteableLen()<len){
        makeSpace(len);
    }
    std::copy(msg,msg+len,buffer_.begin()+writeIndex_);
    writeIndex_+=len;
}
void Buffer::append(const std::string& str){
    append(str.data(),str.size());
}
ssize_t Buffer::readFd(int sockFd,int* savedRrrno){
    char buf[65536];
    size_t writeableLen =getWriteableLen();
    struct iovec vec[2];
    vec[0].iov_base=&*(buffer_.begin()+writeIndex_);
    vec[0].iov_len=writeableLen;
    vec[1].iov_base=buf;
    vec[1].iov_len=sizeof(buf);
    int count=writeableLen < sizeof(buf)?2:1;

    int n=0;
    ssize_t receiveSum=0;
    while (true)
    {
       n=::readv(sockFd,vec,count);
       if(n<=0){
           *savedRrrno=errno;
           break;
       }else if(n<=writeableLen){
           writeIndex_+=n;
       }
       else{
           writeIndex_=buffer_.size();
           append(buf,n-writeableLen);
           memset(buf,0,sizeof(buf));
       }
       receiveSum+=n;
    }
    return receiveSum;
}
ssize_t Buffer::writeFd(int sockFd,int* savedErrno){
    int n =::write(sockFd,peek(),getReadableLen());
    if(n<=0){
        *savedErrno=errno;
    }
    return n;
}

void Buffer::makeSpace(size_t len){
    if(getWriteableLen() + getPreEmptyLen() <len){
			buffer_.resize(writeIndex_+len);//扩容
		}
		else{  //数据搬移
			size_t dataSize = getReadableLen();
			std::copy(buffer_.begin()+readIndex_, buffer_.begin()+writeIndex_, buffer_.begin());
			readIndex_ = 0;
			writeIndex_ = dataSize;
        }
}



}



}