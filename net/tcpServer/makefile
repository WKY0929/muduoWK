
MUDUOWK_DIRECTORY =/home/ywk/muduoWK
TARGET=tcpServer
LIBS=-lpthread

GDB=

OBJS=TcpServer.o $(MUDUOWK_DIRECTORY)/base/Logger.o $(MUDUOWK_DIRECTORY)/base/LogStream.o \
	$(MUDUOWK_DIRECTORY)/base/AsyncLogging.o $(MUDUOWK_DIRECTORY)/base/Thread.o $(MUDUOWK_DIRECTORY)/base/LogFile.o \
	$(MUDUOWK_DIRECTORY)/base/TimeStamp.o $(MUDUOWK_DIRECTORY)/net/Channel.o $(MUDUOWK_DIRECTORY)/net/Epoller.o \
	$(MUDUOWK_DIRECTORY)/net/EventLoop.o $(MUDUOWK_DIRECTORY)/net/Socket.o $(MUDUOWK_DIRECTORY)/net/timer/TimerWheel.o \
	$(MUDUOWK_DIRECTORY)/net/timer/TimerWheelsThread.o $(MUDUOWK_DIRECTORY)/net/EventLoopThread.o \
	$(MUDUOWK_DIRECTORY)/net/EventLoopThreadPool.o $(MUDUOWK_DIRECTORY)/net/tcpServer/Acceptor.o  \
	$(MUDUOWK_DIRECTORY)/net/tcpServer/Buffer.o $(MUDUOWK_DIRECTORY)/net/tcpServer/Connection.o 
CXXFLAGS=-I$(MUDUOWK_DIRECTORY)

$(TARGET):$(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS) $(GDB) 
%.o:%.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@ $(LIBS) $(GDB)
clean :
	rm $(OBJS) $(TARGET)
.PHONY: clean