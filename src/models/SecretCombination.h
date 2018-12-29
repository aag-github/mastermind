#ifndef SRC_SECRETCOMBINATION_H_
#define SRC_SECRETCOMBINATION_H_

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

    SecretCombination operator=(const std::string &s) {
        assert(s.size() == colors.size());
        for(size_t i = 0; i < std::min(s.size(), colors.size()); i++) {
            colors[i] = ColorList::getColor(s[i]);
        }
        return *this;
    }
};

}

#endif
