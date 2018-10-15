#ifndef SRC_CONTROLLERS_READCOMBINATIONVIEWCONTROLLER_H_
#define SRC_CONTROLLERS_READCOMBINATIONVIEWCONTROLLER_H_

#include "ProposedCombinationList.h"

namespace Mastermind {

class ReadCombinationViewController {
public:
    ReadCombinationViewController(){
    }

    virtual ~ReadCombinationViewController() {
    }

    virtual const ProposedCombinationList& getProposedCombinations() = 0;

    virtual void setProposedCombination(size_t position, const Combination& proposedCombination) = 0;

    virtual bool isGameFinished(size_t position) = 0;

    virtual void gameEnd(size_t position) = 0;
};


}

#endif
