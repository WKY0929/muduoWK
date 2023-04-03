#include "../net/Socket.h"


int main()
{
    Socket sock(1316);
    //sock.sockwrite();
    sock.start();
   //sock.start();
    return 0;
}