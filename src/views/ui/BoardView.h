#ifndef SRC_VIEWS_BOARDVIEW_H_
#define SRC_VIEWS_BOARDVIEW_H_

#include "ProposedCombinationView.h"
#include "CombinationView.h"
#include "SecretCombinationView.h"
#include "ViewConst.h"

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

    void show(bool hideSecret) const {
        printf("%s\n\n", SECTION_BREAK.c_str());
        printf("Secret: ");
        if (hideSecret) {
            SecretCombinationView(secretCombination).show();
        } else {
            CombinationView(secretCombination).show();
        }
        printf("\n\n");
        int i = 1;
        for(auto &combination : *proposedCombinationList) {
            printf("   %2d : ", i++);
            ProposedCombinationView(&combination).show();
            printf("\n");
        }
        printf("\n");
    }

private:
    const ProposedCombinationList *proposedCombinationList;

    const Combination *secretCombination;

};

}

#endif
