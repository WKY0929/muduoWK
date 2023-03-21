#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	pid_t pid=-1;
	pid=fork();
	if(pid==0)
	{
		printf("hello world\n");
	
	}else 
	{
		printf("%d %d\n",getpid(),pid);
	}
	return 0;
}
