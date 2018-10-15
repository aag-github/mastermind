#ifndef SRC_VIEWS_BOARDVIEW_H_
#define SRC_VIEWS_BOARDVIEW_H_

#include "ProposedCombinationView.h"

namespace Mastermind {

class BoardView {
public:
    BoardView(const ProposedCombinationList *proposedCombinationList) :
        proposedCombinationList(proposedCombinationList)
    {
    }

    virtual ~BoardView(){
    }

    void show() const {
        printf("_______________________________\n\n");
        int i = 1;
        for(auto &combination : *proposedCombinationList) {
            printf("%2d : ", i++);
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
};

}

#endif
