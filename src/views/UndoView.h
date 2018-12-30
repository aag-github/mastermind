#ifndef SRC_VIEWS_UNDOVIEW_H_
#define SRC_VIEWS_UNDOVIEW_H_

#include "UndoController.h"
#include "ui/BoardView.h"

namespace Mastermind {

class UndoView {
public:
    UndoView(){
    };

    virtual ~UndoView(){
    };

    void interact(UndoController* controller){
        assert(controller != nullptr);

        controller->undo();

        BoardView(&controller->getProposedCombinations(), &controller->getSecretCombination()).show(true);
    }
};

}
#endif
