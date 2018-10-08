#ifndef SRC_MODELS_RESULT_H_
#define SRC_MODELS_RESULT_H_

#include <map>
#include "ResultCounter.h"

namespace Mastermind {

class Result {
public:
    Result() :
        dead(0),
        injured(0)
    {
    }

    void print() {
        printf("D: %d - I: %d", dead, injured);
    }

    void calculateResult(const Combination &proposedCombination, const Combination &secretCombination) {
        dead = 0;
        injured = 0;

        InjuredCounter counter;

        auto proposedColor = proposedCombination.begin();
        auto secretColor = secretCombination.begin();
        while(proposedColor != proposedCombination.end())
        {
            if (*proposedColor == *secretColor){
                dead++;
            } else {
                counter.add(*secretColor, *proposedColor);
            }
            proposedColor++;
            secretColor++;
        }

        injured = counter.calculate();
    }

    bool isRight() {
        return dead == Combination::MAX_COLORS;
    }
private:
    int dead;

    int injured;

};

}

#endif
