#ifndef _MUDUOWK_BASE_FIXEDBUFFER_
#define _MUDUOWK_BASE_FIXEDBUFFER_

#include<iostream>
#include<string.h>
#include "uncopyable.h"

namespace muduoWK{

const int bigBufferSize=4000*1000;//
const int smallBufferSize=4000;

template<int SIZE> //非类型模板参数
class FixedBuffer:uncopyable{

public:
    FixedBuffer():cur_(data_){}
    ~FixedBuffer(){}
    
    void append(const char* msg,size_t len){
        if(static_cast<int>(len)<getRemainLen()){
            memcpy(cur_,msg,len);
            cur_+len;
        }
    }
    void addCurPos(size_t len){cur_+len;}
    void bZero(){memset(data_,0,SIZE);}
    const char* getData()const {return data_;}
    char* current(){return cur_;}
    int getDataLen()const {return static_cast<int>(cur_-data_);}
    int getRemainLen(){return static_cast<int>(end()-cur_);}
    void resetCur(){cur_=data_;}

private:
    const char* end() const {return data_+sizeof(data_);}
    char data_[SIZE];
    char* cur_;
};

}



#endif