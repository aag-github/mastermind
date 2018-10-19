#ifndef SRC_VIEWS_STARTVIEW_H_
#define SRC_VIEWS_STARTVIEW_H_

#include "OperationController.h"

namespace Mastermind {

class StartView {
public:
    StartView(){

    };

    virtual ~StartView(){

    };

    void interact(StartController* controller){
        assert(controller);
        controller->start();
    }
};

}

#endif
