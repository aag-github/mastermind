#ifndef SRC_PROPOSEDCOMBINATION_H_
#define SRC_PROPOSEDCOMBINATION_H_

#include "CharReader.h"
#include "SecretCombination.h"
#include "Result.h"

namespace Mastermind {

class ProposedCombination : public Combination {
public:
    ProposedCombination(const Combination& combination, const Result &result):Combination() {
        *this = combination;
        this->result = result;
    }

    ProposedCombination():Combination() {
    }

    virtual ~ProposedCombination() {
    }

    bool calculateResult(const Combination &secretCombination) {
        result.calculateResult(*this, secretCombination);
        return result.isRight();
    }

    virtual void clear() {
        Combination::clear();
        result = Result();
    }

    ProposedCombination& operator=(const Combination& combination) {
        auto src = combination.begin();
        for(auto& dst : *this){
            dst = *src;
            src++;
        }
        return *this;
    }

    const Result& getResult() const {
        return result;
    }

private:
    Result result;

};

}

#endif
