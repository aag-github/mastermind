#ifndef SRC_MODELS_RESULT_H_
#define SRC_MODELS_RESULT_H_

#include "ResultCounter.h"

namespace Mastermind {

class Result {
public:
    Result(int dead, int injured) :
        dead(dead),
        injured(injured)
    {
    }

    Result() :
        dead(0),
        injured(0)
    {
    }

    void calculateResult(const Combination &proposedCombination, const Combination &secretCombination) {
        dead = 0;
        injured = 0;

        InjuredCounter injuredCounter;

        auto proposedColor = proposedCombination.begin();
        auto secretColor = secretCombination.begin();
        while(proposedColor != proposedCombination.end())
        {
            if (*proposedColor == *secretColor){
                dead++;
            } else {
                injuredCounter.add(*secretColor, *proposedColor);
            }
            proposedColor++;
            secretColor++;
        }

        injured = injuredCounter.calculate();
    }

    bool isRight() const {
        return dead == Combination::MAX_COLORS;
    }

    int getDead() const {
        return dead;
    }

    int getInjured() const {
        return injured;
    }

private:
    int dead;

    int injured;

};

}

#endif
