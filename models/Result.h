#ifndef SRC_MODELS_RESULT_H_
#define SRC_MODELS_RESULT_H_

#include <map>

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

        std::map<ColorList::Color, int> secretCounters;
        std::map<ColorList::Color, int> propposedCounters;
        for(auto color : ColorList::getColors()) {
            secretCounters[color] = 0;
            propposedCounters[color] = 0;
        }

        auto proposedColor = proposedCombination.begin();
        auto secretColor = secretCombination.begin();
        while(proposedColor != proposedCombination.end())
        {
            if (*proposedColor == *secretColor){
                dead++;
            } else {
                secretCounters[*secretColor]++;
                propposedCounters[*proposedColor]++;
            }
            proposedColor++;
            secretColor++;
        }

        auto secretCounter = secretCounters.begin();
        auto proposedCounter = propposedCounters.begin();
        while(secretCounter != secretCounters.end()){
            injured += std::min(secretCounter->second, proposedCounter->second);
            secretCounter++;
            proposedCounter++;
        }
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
