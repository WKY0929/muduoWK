#ifndef MUDUO_NET_THREADPOOL_H
#define MUDUO_NET_THREADPOOL_H
#include<thread>
#include<vector>
#include<queue>
#include<future>
#include<condition_variable>
#include<mutex>
class ThreadPool
{
public:
    explicit ThreadPool(size_t threadNum):stop_(false)
    {
        for(size_t i=0;i<threadNum;++i)
        {
            m_thread.emplace_back(
                [this]()
                {
                    for(;;)
                    {
                        std::function<void()>task;
                        std::unique_lock<std::mutex>lk(m_mutex);
                        m_condition.wait(lk,[this](){return stop_||tasks.empty();});
                        if(stop_&&tasks.empty())return;
                        task=std::move(tasks.front());
                        tasks.pop();

                    task();
                    }
                }
            );
        }
    }
    ThreadPool(const ThreadPool&)=delete;
    ThreadPool(ThreadPool&&)=delete;
    ThreadPool&operator=(const ThreadPool&)=delete;
    ThreadPool&operator=(ThreadPool&&)=delete;
    ~ThreadPool()
    {
        std::unique_lock<std::mutex>lk(m_mutex);
        stop_=true;
        m_condition.notify_all();
        for(auto&threads:m_thread)
        {
            threads.join();
        }
    }
    template<typename F,typename... Args>
    auto submit(F&&f,Args&&... args)->std::future<decltype(f(args...))>{
        auto taskPtr=std::make_shared<std::packaged_task<decltype(f(args...))()>>(
            std::bind(std::forward<F>(f),std::forward<Args>(args)...)
        );
        std::unique_lock<std::mutex>lk(m_mutex);
        if(stop_)throw std::runtime_error("submit on stopped ThreadPool");
        tasks.emplace([taskPtr](){(*taskPtr);});
        m_condition.notify_one();
        return taskPtr->get_future();
    }
private:
    bool stop_;
    std::vector<std::thread>m_thread;
    std::queue<std::function<void()>>tasks;
    std::mutex m_mutex;
    std::condition_variable m_condition;

};

#endif