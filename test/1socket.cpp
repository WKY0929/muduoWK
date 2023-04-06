#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<mutex>
#include<condition_variable>
#include<string>
std::mutex m_mutex;
std::condition_variable condition;
//std::string buf="";
//char buf[1024]="";
void* read(void* arg)
{	
	int cfd=*(int*)arg;
	//std::unique_lock<std::mutex> lk(m_mutex);
	char buf[1024]="";
	int n=read(cfd,buf,sizeof(buf));
	printf("%s\n",buf);
	//lk.unlock();
	//sleep(1);
}
void* write(void* arg){
	//std::unique_lock<std::mutex> lk(m_mutex);
	int cfd=*(int*)arg;
	char buf[1024]="";
	int n=read(STDIN_FILENO,buf,sizeof(buf));
	write(cfd,buf,n);
	//lk.unlock();
	//sleep(1);
}
int main(int argc,char*argv[])
{

	 pthread_t tid1,tid2;	
	// int listenfd=socket(PF_INET,SOCK_STREAM,0);
	// struct sockaddr_in address;
	// bzero(&address,sizeof(address));
	// address.sin_family=AF_INET;
	// address.sin_addr.s_addr=htonl(INADDR_ANY);
	// address.sin_port=htons(8000);
	// int ret=bind(listenfd,(struct sockaddr*)&address,sizeof(address));
	// ret=listen(listenfd,5);
	// struct sockaddr_in client;
	// socklen_t len=sizeof(client);
	// int cfd=accept(listenfd,(struct sockaddr*)&client,&len);
	int port=atoi(argv[1]);
	//printf("port=%d",port);
	int listenfd=socket(PF_INET,SOCK_STREAM,0);
	struct  sockaddr_in address;
	bzero(&address,sizeof(address));
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=htonl(INADDR_ANY);
	address.sin_port=htons(port);
	int ret=bind(listenfd,(struct sockaddr*)&address,sizeof(address));
	ret=listen(listenfd,5);
	struct sockaddr_in client;
	socklen_t len=sizeof(client);
	int cfd=accept(listenfd,(struct sockaddr*)&client,&len); 
	while(1)
	{
		pthread_create(&tid1,NULL,read,(void*)&cfd);
		pthread_create(&tid2,NULL,write,(void*)&cfd);
		
	}
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	close(cfd);
	return 0;
}
