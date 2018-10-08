#ifndef SRC_CONTROLLERS_STARTCONTROLLER_H_
#define SRC_CONTROLLERS_STARTCONTROLLER_H_

#include "OperationController.h"

namespace Mastermind {

class StartController: public OperationController {
public:
    StartController(Game &game) :
        OperationController(game)
    {
    }

    virtual ~StartController(){
    }

    void control() {
        getSecretCombination().random();

        for(auto& combination : getProposedCombination()) {
            combination.clear();
        }

        setState(State::IN_GAME);
    };
};

}

#endif
