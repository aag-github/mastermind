#ifndef SRC_CONTROLLERS_CLIENTLOGIC_H_
#define SRC_CONTROLLERS_CLIENTLOGIC_H_

#include "Logic.h"
#include "GameProxy.h"
#include "StartController.h"
#include "MenuController.h"
#include "StartMenuController.h"

namespace Mastermind {

class ClientLogic : public Logic<ClientOperationController> {
public:
    ClientLogic(Game* game) :
        Logic(game),
        startController(*game),
        menuController(*game),
        startMenuController(*game)
    {
    }
    virtual ~ClientLogic() {
    }

    virtual ClientOperationController* getController() override final {
        switch (game->getState()){
        case State::INITIAL:
            return &startController;
        case State::START_MENU:
            return &startMenuController;
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

    StartMenuController startMenuController;
};

}

#endif
