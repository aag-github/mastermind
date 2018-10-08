#ifndef SRC_MODELS_RESULTCOUNTER_H_
#define SRC_MODELS_RESULTCOUNTER_H_

#include "ColorList.h"

namespace Mastermind {

class InjuredCounter {
public:
    InjuredCounter(){
        for(auto color : ColorList::getColors()) {
            secretCounters[color] = 0;
            propposedCounters[color] = 0;
        }
    }

    virtual ~InjuredCounter(){
    }

    void add(ColorList::Color secretColor, ColorList::Color proposedColor){
        secretCounters[secretColor]++;
        propposedCounters[proposedColor]++;
    }

    int calculate() {
        int injured = 0;
        auto secretCounter = secretCounters.begin();
        auto proposedCounter = propposedCounters.begin();
        while(secretCounter != secretCounters.end()){
            injured += std::min(secretCounter->second, proposedCounter->second);
            secretCounter++;
            proposedCounter++;
        }
        return injured;
    }

private:
    std::map<ColorList::Color, int> secretCounters;
    std::map<ColorList::Color, int> propposedCounters;
};

}

#endif
