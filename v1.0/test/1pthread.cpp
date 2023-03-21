#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#include<pthread.h>

pthread_mutex_t mutex;

void* fun(void* arg)
{
	printf("%d\n",getuid());
	sleep(1);
	return NULL;
}
int main()
{
	pthread_t tid[5];
	int i=0;
	for(;i<5;i++)
	{
		pthread_create(&tid[i],NULL,fun,NULL);
	}
	for(i=0;i<5;i++)
	{
		pthread_join(tid[i],NULL);
	}
	return 0;
}
