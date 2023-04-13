#include "buffer.h"

void Buffer::initPtr()
{
    bzero(&buffer_[0],buffer_.size());
    readPos_=0;
    writePos_=0;
}