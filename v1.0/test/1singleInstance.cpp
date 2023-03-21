#include"1singleInstance.h"
#include<mutex>
mutex Singleton::mu_;
Singleton* Singleton::m_instance;
Singleton::Singleton(){
    std::cout<<"构造函数"<<std::endl;
}
Singleton* Singleton::getInstance(){
    //static std::one_flag fg;
    //std::call_one(fg,[]{return new Task();});
    //return task;
    if(m_instance==nullptr)
    {
        unique_lock<mutex> lk(mu_);
        if(m_instance==nullptr)
        {
            m_instance=new Singleton();
        }
    }
    return m_instance;
}
void Singleton::fun(){
    std::cout<<"hello world"<<std::endl;
}
void dosomething()
{
    Singleton* Singleton=Singleton::getInstance();
    //cout<<m_instance<<endl;
}
int main()
{
  std::thread w1(dosomething);
  std::thread w2(dosomething);
  w1.detach();
  w2.detach();
  getchar();
  return 0;

}