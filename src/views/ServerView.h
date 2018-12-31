#ifndef SRC_VIEWS_SERVERVIEW_H_
#define SRC_VIEWS_SERVERVIEW_H_

#include "OperationController.h"

namespace Mastermind {

class ServerView {
public:
    ServerView(){

    };

    virtual ~ServerView(){

    };

    void interact(ServerController* controller){
        assert(controller != nullptr);

        controller->start();
    }
};

}

#endif
