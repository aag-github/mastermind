#ifndef SRC_VIEWS_PROPOSEDCOMBINATIONVIEW_H_
#define SRC_VIEWS_PROPOSEDCOMBINATIONVIEW_H_

#include "ProposedCombination.h"
#include "CombinationView.h"
#include "ResultView.h"

namespace Mastermind {

class ProposedCombinationView : public CombinationView {
public:
    ProposedCombinationView(const ProposedCombination *proposedCombination) :
        CombinationView(proposedCombination),
        proposedCombination(proposedCombination)
    {
    }

    virtual ~ProposedCombinationView(){
    };

    virtual void show() const {
        CombinationView::show();
        printf(" ");
        ResultView(&proposedCombination->getResult()).show();
    }
private:
    const ProposedCombination *proposedCombination;
};

}

#endif
