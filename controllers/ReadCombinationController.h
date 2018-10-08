#ifndef SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_
#define SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_

#include "OperationController.h"

namespace Mastermind {

class ReadCombinationController: public OperationController {
public:
    ReadCombinationController(Game &game) :
        OperationController(game)
    {
    }

    virtual ~ReadCombinationController(){
    }

    void control() {
        int i = 0;
        bool right = false;
        do {
            this->print();
            ProposedCombination &proposedCombination = getProposedCombination()[i];
            proposedCombination.read();
            proposedCombination.calculateResult(getSecretCombination());
            right = proposedCombination.isRight();
            i++;
        } while (!right && i < Game::MAX_PROPOSED_COMBINATION);

        printResult(i, right);

        setState(State::FINAL);
    }

private:
    void print() {
        printf("------------------------\n");
        int i = 1;
        for(auto &combination : getProposedCombination()) {
            printf("%2d : ", i++);
            combination.print();
            printf("\n");
        }
        printf("\n");
    }

    void printResult(int lastAttempt, bool right)
    {
        this->print();

        if (right){
            printf("You have won in %d tries.\n", (int(lastAttempt)));
        } else {
            printf("Number of attempts exhausted, LOSER!\n");
        }

        printf("The secret combination was: ");
        getSecretCombination().print();
        printf("\n\n");
    }
};

}

#endif
