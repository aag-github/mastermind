#ifndef SRC_CONTROLLERS_READCOMBINATIONVIEWCONTROLLER_H_
#define SRC_CONTROLLERS_READCOMBINATIONVIEWCONTROLLER_H_

#include "ProposedCombinationList.h"

namespace Mastermind {

class ReadCombinationViewController {
public:
    enum class ReadCombinationStatus {
        CONTINUE,
        WIN,
        LOSE
    };

    ReadCombinationViewController(){
    }

    virtual ~ReadCombinationViewController() {
    }

    virtual const ProposedCombinationList& getProposedCombinations() = 0;

    virtual const SecretCombination& getSecretCombination() = 0;

    virtual void setProposedCombination(size_t position, const Combination& proposedCombination) = 0;

    virtual ReadCombinationStatus checkReadCombinationStatus(size_t position) = 0;

    virtual void gameEnd() = 0;
};


}

#endif
