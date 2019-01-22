#ifndef SRC_CONTROLLERS_RESTARTCONTROLLER_H_
#define SRC_CONTROLLERS_RESTARTCONTROLLER_H_

#include "ClientOperationController.h"

namespace Mastermind {

class RestartController : public Controller{
public:
    RestartController(Game &game, bool ask) :
        Controller(game),
        ask(ask)
    {
    }

    virtual ~RestartController(){
    }

    void restart(bool restart) {
        assert(game.getState() == State::MAIN_MENU || game.getState() == State::START_MENU);

        if (restart) {
            game.setState(State::INITIAL);
        } else if (game.getState() == State::START_MENU){
            game.setState(State::MAIN_MENU);
        } else if (game.getState() == State::MAIN_MENU){
            game.setState(State::START_MENU);
        }
    }

    bool askEnabled() {
        return ask;
    }
private:
    bool ask;
};

}

#endif
