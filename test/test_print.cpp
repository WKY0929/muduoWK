#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
// #include<mutex>
#include<pthread.h>

pthread_mutex_t mutex_;
// std::mutex mutex_;
void* print1(void* arg)
{
    // std::unique_lock<std::mutex>lock(mutex_);
    pthread_mutex_lock(&mutex_);
    for(int i='a';i<='z';i++)
    {
        printf("%c",i);
        usleep(100000);
    }
    pthread_mutex_unlock(&mutex_);
    return NULL;
}
void* print2(void* arg)
{
    // std::unique_lock<std::mutex>lock(mutex_);
    pthread_mutex_lock(&mutex_);
    for(int i='A';i<='Z';i++)
    {
        printf("%c",i);
        usleep(10000);
    }
    pthread_mutex_unlock(&mutex_);
    return NULL;
}

int main()
{
    pthread_t tid1,tid2;
    int ret=pthread_mutex_init(&mutex_,NULL);
    pthread_create(&tid1,NULL,print1,NULL);
    pthread_create(&tid2,NULL,print2,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_mutex_destroy(&mutex_);
    return 0;

}