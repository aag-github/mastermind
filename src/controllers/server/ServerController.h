#ifndef SRC_CONTROLLERS_SERVER_SERVERCONTROLLER_H_
#define SRC_CONTROLLERS_SERVER_SERVERCONTROLLER_H_

#include "OperationController.h"
#include "TCPServer.h"

namespace Mastermind {

//void * loop(void * m);

class ServerController: public OperationController {
public:
    ServerController(Game &game, int port) :
        OperationController(game)
    {
        tcpServer.setup(port);
    }

    virtual ~ServerController(){
    }

    void start() {
        std::cout << "Starting server.....\n";
        pthread_t msg;
        if(pthread_create(&msg, NULL, loop, (void *)this) == 0)
        {
            tcpServer.receive();
        }
    };

    virtual void accept(OperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

    static void * loop(void * m);

private:
    TCPServer tcpServer;

    std::string Interpret(std::string request) {
        std::cout << "got:" << request << "\n";

        std::string response;

        response = request + " back to you";

        return response;
    }
};

void * ServerController::loop(void * m)
{
    ServerController* serverController = (ServerController*)m;
    TCPServer &tcpServer = serverController->tcpServer;
    pthread_detach(pthread_self());
    while(1)
    {
        std::string str = tcpServer.getMessage();
        if( str != "" )
        {
            tcpServer.Send(serverController->Interpret(str));
            tcpServer.clean();
        }
        usleep(1000);
    }
    tcpServer.detach();
}

}

#endif
