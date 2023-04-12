#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>

int main()
{
    int fd[2]={0,0};
    int sock=socketpair(AF_LOCAL,SOCK_STREAM,0,fd);
    if(sock<0)
    {
        perror("socketpair");
        exit(1);
    }
    pid_t id=fork();
    if(id<0)
    {
        perror("fork");
        exit(2);
    }else if(id==0)
    {
        close(fd[0]);
        char buf[1024]; 
        while(1)
        {
            memset(buf,'\0',sizeof(buf));
            strcpy(buf,"hello world");
            write(fd[1],buf,sizeof(buf)-1);
            read(fd[1],buf,sizeof(buf)-1);
            sleep(1);
            printf("%s\n",buf);
        }
    }else{
        close(fd[1]);
        char buf[1024];
        while (1)
        {
            read(STDIN_FILENO,buf,sizeof(buf)-1);/* code */
            printf("child %s\n",buf);
            memset(buf,'\0',sizeof(buf));
            // strcpy(buf,"nihao");
            write(fd[0],buf,sizeof(buf)-1);
            sleep(1);
        }
        close(fd[0]);
        
    }
    return 0;
}
