#include "../net/Tcpserver.h"

int main()
{
    Tcpserver sev(1316);
    sev.start();
    return 0;
}