#ifndef SRC_CONTROLLERS_SERVER_SERVERCONTROLLER_H_
#define SRC_CONTROLLERS_SERVER_SERVERCONTROLLER_H_

#include "OperationController.h"
#include "TCPServer.h"
#include "Game.h"
#include "ServerInterpreter.h"

namespace Mastermind {

class ServerController: public ServerOperationController {
public:
    ServerController(Game &game, int port) :
        ServerOperationController(game)
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

    virtual void accept(ServerOperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

    static void * loop(void * m);

private:
    TCPServer tcpServer;

    std::string Interpret(std::string request) {
        auto separator = request.find(':');
        std::string command = request.substr(0, separator);
        std::string value = request.substr(separator +1);

        ServerInterpreterContext context(&game, command, value);

        ServerInterpreter interpreter;

        interpreter.interpret(&context);

        return context.getReply();
    }
};

}

#endif
