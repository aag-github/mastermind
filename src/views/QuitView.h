#ifndef SRC_VIEWS_QUITVIEW_H_
#define SRC_VIEWS_QUITVIEW_H_

#include "QuitController.h"
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

        controller->quit(DialogYesNoView().read("Are you sure you want to quit (Y/N)?"));
        printf("\n");
    }
};

}
#endif
