#ifndef SRC_SECRETCOMBINATION_H_
#define SRC_SECRETCOMBINATION_H_

#include "ColorList.h"
#include "Combination.h"

namespace Mastermind {

class SecretCombination : public Combination {
public:
    SecretCombination():Combination(){
    }

    virtual ~SecretCombination() {
    }

    void random()
    {
        for (auto &color : colors){
            color = ColorList::getRandom();
        }
    }
};

}

#endif
