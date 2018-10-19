#ifndef SRC_CONTROLLERS_STARTCONTROLLER_H_
#define SRC_CONTROLLERS_STARTCONTROLLER_H_

#include <assert.h>
#include "CombinationController.h"

namespace Mastermind {

class StartController: public CombinationController {
public:
    StartController(Game &game) :
        CombinationController(game)
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
