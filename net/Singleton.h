#ifndef MUDUO_SINGLETON_H
#define MUDUO_SINGLETON_H
#include <assert.h>
#include <pthread.h>

template<typename T>
class Singleton
{
public:
    static T&instance()
    {
        pthread_once(&ponce_,Singleton::init);
        assert(value_!=NULL);
        return *value_;
    }
private:
    Singleton();
    ~Singleton();
    // Singleton(const Singleton&)=delete;
    // Singleton& operator=(const SIngleton&)=delete;
    // Singleton&(const Singleton&&)=delete;
    // Singleton& operator=(const Singleton&&)=delete;
    static void init()
    {
        value_=new T();
    }
private:
    static pthread_once_t ponce_;
    static T*             value_;
};
template<typename T>
pthread_once_t Singleton<T>::ponce_=PTHREAD_ONCE_INIT;
template<typename T>
T* Singleton<T>::value_=NULL;


#endif