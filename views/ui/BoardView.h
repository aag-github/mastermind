#ifndef SRC_VIEWS_BOARDVIEW_H_
#define SRC_VIEWS_BOARDVIEW_H_

#include "ProposedCombinationView.h"
#include "CombinationView.h"

namespace Mastermind {

class BoardView {
public:
    BoardView(const ProposedCombinationList *proposedCombinationList, const Combination *secretCombination) :
        proposedCombinationList(proposedCombinationList),
        secretCombination(secretCombination)
    {
    }

    virtual ~BoardView(){
    }

    void show(bool hideSecret = false) const {
        printf("_______________________________\n\n");
        printf("Secret: ");
        CombinationView(secretCombination).show(hideSecret);
        printf("\n\n");
        int i = 1;
        for(auto &combination : *proposedCombinationList) {
            printf("   %2d : ", i++);
            ProposedCombinationView(&combination).show();
            printf("\n");
        }
        printf("\n");
    }

    void update(size_t position) const {
        show();
    }

private:
    const ProposedCombinationList *proposedCombinationList;

    const Combination *secretCombination;

};

}

#endif
