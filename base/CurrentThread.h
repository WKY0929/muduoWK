#ifndef _MUDUOZ_BASE_CURRENTTHREAD_
#define _MUDUOZ_BASE_CURRENTTHREAD_

#include<stdio.h>
#include<sys/prctl.h>
#include<sys/syscall.h>
#include<unistd.h>
namespace muduoWK{

namespace CurrentThread{

extern __thread int t_cachedTid;
extern __thread char t_tidString[32];
extern __thread int t_tidStringLength;
extern __thread const char* t_threadName;

pid_t gettid();
void cacheTid();
inline int tid() {
    if (__builtin_expect(t_cachedTid == 0, 0)) cacheTid();
    return t_cachedTid;//直接返回缓存的id
}

inline const char* tidString()  {
    return t_tidString;
}

inline int tidStringLength()  {
    return t_tidStringLength;
}

inline const char* name() { 
    return t_threadName; 
}

}

} //namespace muduoWK


#endif