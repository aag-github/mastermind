#ifndef SRC_VIEWS_CONTINUEVIEW_H_
#define SRC_VIEWS_CONTINUEVIEW_H_

#include "DialogYesNoView.h"
#include "ContinueController.h"

namespace Mastermind {

class ContinueView {
public:
    ContinueView(){
    };

    virtual ~ContinueView(){
    };

    void interact(ContinueViewController* controller){
        assert(controller);
        controller->resume(DialogYesNoView().read("Play again (Y/N)?"));
        printf("\n");
    }
};

}

#endif
