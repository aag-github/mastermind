#ifndef SRC_VIEWS_READCOMBINATIONVIEW_H_
#define SRC_VIEWS_READCOMBINATIONVIEW_H_

#include "ReadCombinationViewController.h"
#include "./ui/BoardView.h"

namespace Mastermind {

class ReadCombinationView {
public:
    ReadCombinationView(){
    };

    virtual ~ReadCombinationView(){
    };

    void interact(ReadCombinationViewController* controller){
        assert(controller);
        assert(controller->getProposedCombinations().size() != 0);

        BoardView(&controller->getProposedCombinations()).show();

        bool gameEnd = false;
        size_t i = 0;
        while(!gameEnd) {
            controller->setProposedCombination(i, CombinationView::read());
            gameEnd = controller->isGameFinished(i);
            BoardView(&controller->getProposedCombinations()).update(i);
            i++;
        }
        controller->gameEnd(i - 1);
    }

};

}

#endif
