#ifndef BUFFER_H
#define BUFFER_H
#include<atomic>
#include<sys/uio.h>

class Buffer
{
public:
    Buffer(int initBufferSize=1024);
    ~Buffer()=default;
    size_t writeableBytes()const;
    size_t readableBytes()const;
    size_t readBytes()const;
    const char *curReadPtr()const;

};


#endif