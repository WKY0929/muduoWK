#include<arpa/inet.h>
#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>

int main()
{
    int sockfd;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(1316);
    inet_pton(AF_INET,"127.0.0.1",&addr.sin_addr.s_addr);
    connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
    pid_t pid=fork();
    if(pid==0)
    {
        // while(1)
        // {
            char buf[1024]="";
            int n=read(STDIN_FILENO,buf,sizeof(buf));
            write(sockfd,buf,n);
        // }
    }else
    {
        while(1)
        {
            char buf2[1024]="";
            int n=read(sockfd,buf2,sizeof(buf2));
            printf("server:%s\n",buf2);
            if(n<-1)
            {
                break;
            }
        }
    }
    
    close(sockfd);
    return 0;
}