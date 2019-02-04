#ifndef SRC_CONTROLLERS_CLIENTOPERATIONCONTROLLERVISITOR_H_
#define SRC_CONTROLLERS_CLIENTOPERATIONCONTROLLERVISITOR_H_

namespace Mastermind {

class StartController;
class StartMenuController;
class MainMenuController;

class ClientOperationControllerVisitor {
public:
    ClientOperationControllerVisitor(){};
    virtual ~ClientOperationControllerVisitor(){};

    virtual void visit(StartController *startController) = 0;

    virtual void visit(MainMenuController *menuController) = 0;

    virtual void visit(StartMenuController *menuController) = 0;
};

}

#endif
