## High-performance TCP service framework
### 项目介绍
#### 日志系统
日志系统以异步的方式运行，分为前端和后端两个部分
1. 前端
前端有两块buffer：A和B，前端往bufferA填数据，当数据A被填满后，前端往
bufferB填入新的日志消息，此时的bufferA交由后端处理。
2. 后端
后端由前端或者定时唤醒，后端也有两块buffer:C和D。当后端接收到bufferA时，会将bufferA的
数据写入文件，为了维持前端能够继续读取数据，后端会将bufferC提供给前端。
#### TcpServer
采用one loop per thread的思想开发多线程网络服务器，采用reactor结构
#### 定时器
定时器采用多层时间轮机制，单独作为一个线程工作，以sleep作为tick来源
### 使用说明
```shell
git clone https://github.com/WKY0929/muduoWK.git
cd muduoWK
cd net/tcpServer
make #编译
./tcpServer #运行   
```
