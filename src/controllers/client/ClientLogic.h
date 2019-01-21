#ifndef SRC_CONTROLLERS_CLIENTLOGIC_H_
#define SRC_CONTROLLERS_CLIENTLOGIC_H_

#include "Logic.h"
#include "GameProxy.h"
#include "StartController.h"
#include "ReadCombinationController.h"
#include "MenuController.h"
#include "QuitController.h"
#include "RestartController.h"
#include "LoadGameController.h"
#include "SaveGameController.h"
#include "UndoController.h"
#include "RedoController.h"

namespace Mastermind {

class ClientLogic : public Logic<ClientOperationController> {
public:
    ClientLogic(Game* game) :
        Logic(game),
        startController(*game),
        menuController(*game)
    {
    }
    virtual ~ClientLogic() {
    }

    virtual ClientOperationController* getController() override final {
        switch (game->getState()){
        case State::INITIAL:
            return &startController;
        case State::MAIN_MENU:
            return &menuController;
        case State::EXIT:
            game->setState(State::INITIAL);
            return nullptr;
        default:
            assert(false);
            return nullptr;
        }
}
private:
    StartController startController;

    MenuController menuController;
};

}

#endif
