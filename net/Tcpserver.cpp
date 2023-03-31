#include "Tcpserver.h"


//Tcpserver::Tcpserver
Tcpserver::Tcpserver(int port):ServerSocket_(port)
{
    int Serverfd_=ServerSocket_.getFd();
    

}

void Tcpserver::start()
{
    
}
