#ifndef SRC_CONTROLLERS_QUITCONTROLLER_H_
#define SRC_CONTROLLERS_QUITCONTROLLER_H_

#include "ClientOperationController.h"

namespace Mastermind {

class QuitController : public Controller{
public:
    QuitController(Game &game) : Controller(game)
    {
    }

    virtual ~QuitController(){
    }

    void quit(bool quit) {
        assert(game.getState() == State::MAIN_MENU || game.getState() == State::START_MENU);

        if (quit) {
            game.setState(State::EXIT);
        }
    }
};

}

#endif
