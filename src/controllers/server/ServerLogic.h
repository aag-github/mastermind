#ifndef SRC_CONTROLLERS_SERVERLOGIC_H_
#define SRC_CONTROLLERS_SERVERLOGIC_H_

#include "Logic.h"
#include "Game.h"
#include "ServerController.h"

namespace Mastermind {

class ServerLogic : public Logic<ServerOperationController> {
public:
    ServerLogic(Game* game, int port) :
        Logic(game),
        serverController(*game, port)
    {
    }

    virtual ~ServerLogic() {
    }

    virtual ServerOperationController* getController() override final {
        return &serverController;
    }

private:
    ServerController serverController;
};

}

#endif
