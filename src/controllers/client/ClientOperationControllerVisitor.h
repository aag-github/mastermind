#ifndef SRC_CONTROLLERS_CLIENTOPERATIONCONTROLLERVISITOR_H_
#define SRC_CONTROLLERS_CLIENTOPERATIONCONTROLLERVISITOR_H_

namespace Mastermind {

class StartController;
class StartMenuController;
class MenuController;

class ClientOperationControllerVisitor {
public:
    ClientOperationControllerVisitor(){};
    virtual ~ClientOperationControllerVisitor(){};

    virtual void visit(StartController *startController) = 0;

    virtual void visit(MenuController *menuController) = 0;

    virtual void visit(StartMenuController *menuController) = 0;
};

}

#endif
