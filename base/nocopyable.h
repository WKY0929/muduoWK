#ifndef MUDUO_BASE_NOCOPYABLE_H
#define MUDUO_BASE_NOCOPYABLE_H

namespace muduo
{
    class noncopyable
    {
        public:
            noncopyable(const noncopyable&)=delete;
            void operator=(const noncopyable&)=delete;
        protected:
            noncopyable()=default;
            ~noncopyable()=default;
    };
     
    
} // namespace muduo

#endif
 