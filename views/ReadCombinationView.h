#ifndef SRC_VIEWS_READCOMBINATIONVIEW_H_
#define SRC_VIEWS_READCOMBINATIONVIEW_H_

#include "ReadCombinationViewController.h"
#include "./ui/BoardView.h"
#include "./ui/GameEndView.h"

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

        ReadCombinationViewController::ReadCombinationStatus status = ReadCombinationViewController::ReadCombinationStatus::CONTINUE;
        size_t i = 0;
        while(status == ReadCombinationViewController::ReadCombinationStatus::CONTINUE) {
            controller->setProposedCombination(i, CombinationView::read());
            status = controller->checkReadCombinationStatus(i);
            BoardView(&controller->getProposedCombinations()).update(i);
            i++;
        }

        GameEndView(&controller->getSecretCombination(), status == ReadCombinationViewController::ReadCombinationStatus::WIN).show();

        controller->gameEnd();
    }

};

}

#endif
