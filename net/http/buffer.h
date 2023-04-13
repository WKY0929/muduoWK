#ifndef BUFFER_H
#define BUFFER_H
#include<atomic>
#include<vector>
#include<sys/uio.h>
#include<strings.h>
class Buffer
{
public:
    Buffer(int initBufferSize=1024);
    ~Buffer()=default;
    void initPtr();
    size_t writeableBytes()const;//缓存区可以读取的字节数
    size_t readableBytes()const;//缓存区可以写入多少字节数
    size_t readBytes()const;//缓存区已经读取的字节数
    const char *curReadPtr()const;
    const char* curWritePtrConst()const;
    char* curWritePtr();
    void updateReadPtrUntilEnd(const char* end);//将读指针直接更新到指定位置
private:
    std::vector<char>buffer_;
    std::atomic<std::size_t>readPos_;
    std::atomic<std::size_t>writePos_;
};


#endif