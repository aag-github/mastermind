#ifndef SRC_VIEWS_SERVERMASTERMINDVIEW_H_
#define SRC_VIEWS_SERVERMASTERMINDVIEW_H_

#include <assert.h>
#include "server/ServerOperationController.h"
#include "server/ServerOperationControllerVisitor.h"
#include "ServerView.h"

namespace Mastermind {

class ServerController;


class ServerMastermindView : public ServerOperationControllerVisitor {
public:
    ServerMastermindView(){};
    virtual ~ServerMastermindView(){};


    void interact(ServerOperationController *operationController) {
        assert(operationController != nullptr);
        operationController->accept(this);
    }

    virtual void visit(ServerController *serverController) override final {
        assert(serverController != nullptr);
        serverView.interact(serverController);
    }
private:
    ServerView serverView;
};

}

#endif
