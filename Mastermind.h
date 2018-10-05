#ifndef _MASTERMIND_H
#define _MASTERMIND_H

#include <vector>
#include <time.h>
#include <cstdlib>
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
        int i = 0;
        do {
            proposedCombination[i].read();
            proposedCombination[i].calculateResult(secretCombination);

            this->print();

            i++;
        } while (!proposedCombination[i-1].isRight() && i < MAX_PROPOSED_COMBINATION);
    }

    void print() {
        secretCombination.print();
        for(auto &combination : proposedCombination) {
            combination.print();
        }
    }
};

}
#endif
