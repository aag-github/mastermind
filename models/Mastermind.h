#ifndef _MASTERMIND_H
#define _MASTERMIND_H

#include <vector>
#include <time.h>
#include "ProposedCombination.h"
#include "SecretCombination.h"

namespace Mastermind
{

class Mastermind {
private:
    static constexpr int MAX_PROPOSED_COMBINATION = 10;

    SecretCombination secretCombination;

    std::vector<ProposedCombination> proposedCombination;

public:
    Mastermind()
    {
        srand(time(nullptr));
        proposedCombination.resize(MAX_PROPOSED_COMBINATION);
    };

    void play()
    {
        secretCombination.random();
        int i = 0;
        bool right = false;
        do {
            this->print();
            proposedCombination[i].read();
            proposedCombination[i].calculateResult(secretCombination);
            right = proposedCombination[i].isRight();
            i++;
        } while (!right && i < MAX_PROPOSED_COMBINATION);

        printResult(i, right);
    }

    void print() {
        printf("------------------------\n");
        int i = 1;
        for(auto &combination : proposedCombination) {
            printf("%2d : ", i++);
            combination.print();
            printf("\n");
        }
        printf("\n");
    }

    void printResult(int lastAttempt, bool right)
    {
        printf("-----------------------------\n");

        this->print();

        if (right){
            printf("\nYou have won in %d tries.\n", (int(lastAttempt)));
        } else {
            printf("\nNumber of attempts exhausted, LOSER!\n");
        }

        printf("The secret combination was: ");
        secretCombination.print();
        printf("\n\n");
    }
};

}
#endif
