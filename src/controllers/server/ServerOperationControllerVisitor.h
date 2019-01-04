#ifndef SRC_CONTROLLERS_SERVEROPERATIONCONTROLLERVISITOR_H_
#define SRC_CONTROLLERS_SERVEROPERATIONCONTROLLERVISITOR_H_

namespace Mastermind {

class ServerController;

class ServerOperationControllerVisitor {
public:
    ServerOperationControllerVisitor(){};
    virtual ~ServerOperationControllerVisitor(){};

    virtual void visit(ServerController *serverController) = 0;

};

}

#endif
