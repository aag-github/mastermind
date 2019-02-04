#ifndef SRC_CONTROLLERS_QUITCONTROLLER_H_
#define SRC_CONTROLLERS_QUITCONTROLLER_H_

#include "ClientOperationController.h"

namespace Mastermind {

class QuitController{
public:
    virtual ~QuitController(){
    }

    virtual void quit(bool quit) = 0;
};


class QuitControllerImpl : public Controller, public QuitController{
public:
    QuitControllerImpl(Game &game) : Controller(game)
    {
    }

    virtual ~QuitControllerImpl(){
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
