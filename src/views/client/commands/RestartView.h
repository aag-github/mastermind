#ifndef SRC_VIEWS_RESTARTVIEW_H_
#define SRC_VIEWS_RESTARTVIEW_H_

#include "client/RestartController.h"
#include "./ui/DialogYesNoView.h"

namespace Mastermind {

class RestartView {
public:
    RestartView(){
    };

    virtual ~RestartView(){
    };

    void interact(RestartController* controller){
        assert(controller != nullptr);

        if (DialogYesNoView().read("\nAre you sure you want to restart (Y/N)?")) {
            controller->restart();
        }
    }
};

}
#endif
