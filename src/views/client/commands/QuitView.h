#ifndef SRC_VIEWS_QUITVIEW_H_
#define SRC_VIEWS_QUITVIEW_H_

#include "client/QuitController.h"
#include "./ui/DialogYesNoView.h"

namespace Mastermind {

class QuitView {
public:
    QuitView(){
    };

    virtual ~QuitView(){
    };

    void interact(QuitController* controller){
        assert(controller != nullptr);

        controller->quit(DialogYesNoView().read("\nAre you sure you want to quit (Y/N)?"));
        printf("\n");
    }
};

}
#endif
