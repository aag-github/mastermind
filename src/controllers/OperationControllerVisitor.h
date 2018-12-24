#ifndef SRC_CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_
#define SRC_CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_

namespace Mastermind {

class StartController;
class ReadCombinationController;
class ContinueController;
class MenuController;
class QuitController;
class RestartController;

class OperationControllerVisitor {
public:
    OperationControllerVisitor(){};
    virtual ~OperationControllerVisitor(){};

    virtual void visit(StartController *startController) = 0;

    virtual void visit(ReadCombinationController *readCombinationController) = 0;

    virtual void visit(ContinueController *continueController) = 0;

    virtual void visit(MenuController *menuController) = 0;

    virtual void visit(QuitController *continueController) = 0;

    virtual void visit(RestartController *restartController) = 0;
};

}

#endif
