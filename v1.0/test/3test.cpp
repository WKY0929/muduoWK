#include<iostream>
#include<thread>
#include<vector>
#include<mutex>

std::mutex m_mutex;
int cnt=0;
void work(int i)
{
     std::unique_lock<std::mutex>(m_mutex);
    // std::cout<<"do some working"<<i<<" "<<std::this_thread::get_id()<<std::endl;
    //std::unique_lock<std::mutex>(m_mutex);
    for(int j=0;j<100000;j++){
        cnt++;
    }
}
int main()
{
    std::cout<<std::thread::hardware_concurrency()<<std::endl;
    std::vector<std::thread>m_thread;
    //std::thread w(work);
    for(int i=0;i<2;i++){
        m_thread.push_back(std::thread(work,i));
    }
    for(int i=0;i<2;i++){
        m_thread[i].join();
    }
    if(cnt==200000){
        std::cout<<"true"<<std::endl;
    }else{
        std::cout<<"false"<<std::endl;
    }
    //std::cout<<"main func wait"<<std::endl;
    //w.join();
    return 0;
}