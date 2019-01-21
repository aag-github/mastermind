#ifndef SRC_VIEWS_STARTVIEW_H_
#define SRC_VIEWS_STARTVIEW_H_

#include "client/StartController.h"

namespace Mastermind {

class StartView {
public:
    StartView(){

    };

    virtual ~StartView(){

    };

    void interact(StartController* controller){
        assert(controller != nullptr);

        controller->start();
    }
};

}

#endif
