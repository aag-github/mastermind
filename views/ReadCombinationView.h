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

        ReadCombinationStatus status = controller->setProposedCombination(CombinationView::read());

        BoardView(&controller->getProposedCombinations(), &controller->getSecretCombination()).show(status == ReadCombinationStatus::CONTINUE);

        if (status != ReadCombinationStatus::CONTINUE) {
            GameEndView(&controller->getSecretCombination(), status == ReadCombinationStatus::WIN).show();
            controller->gameEnd();
        }
    }

};

}

#endif
