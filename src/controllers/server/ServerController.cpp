#include "ServerController.h"

namespace Mastermind {

void * ServerController::loop(void * m)
{
    ServerController* serverController = (ServerController*)m;
    TCPServer &tcpServer = serverController->tcpServer;
    pthread_detach(pthread_self());
    while(1)
    {
        std::string str = tcpServer.getMessage();
        if(str != "")
        {
            std::cout << "got: '" << str << "'\n";
            std::string send = serverController->Interpret(str);
            std::cout << "sent: '" << send << "'\n";
            tcpServer.Send(send);
            tcpServer.clean();
        }
        usleep(1000);
    }
    tcpServer.detach();
}

}
