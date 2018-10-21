#ifndef SRC_VIEWS_CONTINUEVIEW_H_
#define SRC_VIEWS_CONTINUEVIEW_H_

#include "ContinueController.h"
#include "./ui/DialogYesNoView.h"

namespace Mastermind {

class ContinueView {
public:
    ContinueView(){
    };

    virtual ~ContinueView(){
    };

    void interact(ContinueController* controller){
        assert(controller);

        controller->resume(DialogYesNoView().read("Play again (Y/N)?"));
        printf("\n");
    }
};

}

#endif
