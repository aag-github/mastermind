#ifndef SRC_CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_
#define SRC_CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_

namespace Mastermind {

class StartController;
class ReadCombinationController;
class ContinueController;
class MenuController;
class QuitController;
class RestartController;
class LoadGameController;
class SaveGameController;
class UndoController;
class RedoController;
class ServerController;

class ClientOperationControllerVisitor {
public:
    ClientOperationControllerVisitor(){};
    virtual ~ClientOperationControllerVisitor(){};

    virtual void visit(StartController *startController) = 0;

    virtual void visit(ReadCombinationController *readCombinationController) = 0;

    virtual void visit(ContinueController *continueController) = 0;

    virtual void visit(MenuController *menuController) = 0;

    virtual void visit(QuitController *continueController) = 0;

    virtual void visit(RestartController *restartController) = 0;

    virtual void visit(LoadGameController *loadGameController) = 0;

    virtual void visit(SaveGameController *saveGameController) = 0;

    virtual void visit(UndoController *undoController) = 0;

    virtual void visit(RedoController *redoController) = 0;

    virtual void visit(ServerController *serverController) = 0;

};

class ServerOperationControllerVisitor {
public:
    ServerOperationControllerVisitor(){};
    virtual ~ServerOperationControllerVisitor(){};

    virtual void visit(ServerController *serverController) = 0;

};

}

#endif
