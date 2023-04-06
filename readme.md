### 基于muduo的服务器框架

#### 项目介绍
项目参考moduo，基于epoll的网络编程框架，采用reactor模型，日志采用双缓冲机制，定时器采用多层时间轮

#### 使用说明
**压力测试**
1.
```git
    git clone -b v0.1 https://github.com/WKY0929/muduoWK.git

```
2.
```shell
    cd net/
    cd HttpServer/
    ./HttpServer
    //新建终端
    cd webbench-1.5/
    ./webbench -c 并发数 -t 时间 http://127.0.0.1:端口号/
```
