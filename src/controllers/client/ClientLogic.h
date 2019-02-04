#ifndef SRC_CONTROLLERS_CLIENTLOGIC_H_
#define SRC_CONTROLLERS_CLIENTLOGIC_H_

#include <client/MainMenuController.h>
#include "Logic.h"
#include "GameProxy.h"
#include "StartController.h"
#include "StartMenuController.h"

namespace Mastermind {

class ClientLogic : public Logic<ClientOperationController> {
public:
    ClientLogic(Game* game) :
        Logic(game),
        menuController(*game),
        startMenuController(*game)
    {
    }
    virtual ~ClientLogic() {
    }

    virtual ClientOperationController* getController() override final {
        switch (game->getState()){
        case State::START_MENU:
            return &startMenuController;
        case State::MAIN_MENU:
            return &menuController;
        case State::EXIT:
            game->setState(State::START_MENU);
            return nullptr;
        default:
            assert(false);
            return nullptr;
        }
}
private:
    MainMenuController menuController;

    StartMenuController startMenuController;
};

}

#endif
