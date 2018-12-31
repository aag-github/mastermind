#ifndef SRC_CONTROLLERS_SERVERLOGIC_H_
#define SRC_CONTROLLERS_SERVERLOGIC_H_

#include "Logic.h"
#include "GameLocal.h"
#include "ServerController.h"

namespace Mastermind {

class ServerLogic : public Logic {
public:
    ServerLogic(int port) :
        serverController(game, port)
    {
    }

    virtual ~ServerLogic() {
    }

    virtual OperationController* getController() override final {
        return &serverController;
    }

private:
    GameLocal game;

    ServerController serverController;
};

}

#endif
