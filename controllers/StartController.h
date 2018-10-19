#ifndef SRC_CONTROLLERS_STARTCONTROLLER_H_
#define SRC_CONTROLLERS_STARTCONTROLLER_H_

#include <assert.h>
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

    void start() {
        getSecretCombination().random();

        for(auto& combination : getProposedCombinations()) {
            combination.clear();
        }

        setState(State::IN_GAME);
    };

    virtual void accept(OperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };
};

}

#endif
