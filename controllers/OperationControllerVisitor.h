#ifndef SRC_CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_
#define SRC_CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_

namespace Mastermind {

class StartController;
class ReadCombinationController;
class ContinueController;

class OperationControllerVisitor {
public:
    OperationControllerVisitor(){};
    virtual ~OperationControllerVisitor(){};

    virtual void visit(StartController *startController) = 0;

    virtual void visit(ReadCombinationController *readCombinationController) = 0;

    virtual void visit(ContinueController *continueController) = 0;

};

}

#endif
