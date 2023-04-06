#include<iostream>
#include<thread>
#include<vector>
int cnt=0;

void work(int i)
{
	for(int i=0;i<1000;i++)
	{
		cnt++;
	}
}
int main()
{
	int thread_num=std::thread::hardware_concurrency();
	std::cout<<thread_num<<std::endl;
	std::thread threads[thread_num];
	for(int i=0;i<thread_num;i++)
	{
		threads[i]=std::thread(work,i);	
	}
	for(auto& t:threads)
	{
		t.join();
	}
	std::cout<<"main thread  "<<cnt<<std::endl;
	return 0;
}
