#ifndef SRC_VIEWS_READCOMBINATIONVIEW_H_
#define SRC_VIEWS_READCOMBINATIONVIEW_H_

#include "./ui/BoardView.h"
#include "./ui/GameEndView.h"

namespace Mastermind {

class ReadCombinationView {
public:
    ReadCombinationView(){
    };

    virtual ~ReadCombinationView(){
    };

    void interact(ReadCombinationController* controller){
        assert(controller);
        assert(controller->getProposedCombinations().size() != 0);

        BoardView(&controller->getProposedCombinations()).show();

        ReadCombinationController::ReadCombinationStatus status = ReadCombinationController::ReadCombinationStatus::CONTINUE;
        size_t i = 0;
        while(status == ReadCombinationController::ReadCombinationStatus::CONTINUE) {
            status = controller->setProposedCombination(i, CombinationView::read());
            BoardView(&controller->getProposedCombinations()).update(i);
            i++;
        }

        GameEndView(&controller->getSecretCombination(), status == ReadCombinationController::ReadCombinationStatus::WIN).show();

        controller->gameEnd();
    }

};

}

#endif
