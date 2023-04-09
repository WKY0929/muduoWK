#include "../net/Tcpserver.h"

int main()
{
    Tcpserver sev(1316,2);
    sev.start();
    return 0;
}