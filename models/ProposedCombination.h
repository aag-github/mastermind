/*
 * ProposedCombination.h
 *
 *  Created on: 5 Oct 2018
 *      Author: osboxes
 */

#ifndef SRC_PROPOSEDCOMBINATION_H_
#define SRC_PROPOSEDCOMBINATION_H_

#include "SecretCombination.h"

namespace Mastermind {

class ProposedCombination : public Combination {
public:
    ProposedCombination() {

    }

    virtual ~ProposedCombination() {

    }

    void read(){

    }

    void calculateResult(SecretCombination &secretCombination) {

    }

    bool isRight() {
        return false;
    }

    void print() {

    }
};

} /* namespace mastermind */

#endif /* SRC_PROPOSEDCOMBINATION_H_ */
