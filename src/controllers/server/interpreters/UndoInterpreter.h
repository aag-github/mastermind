#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_UNDOINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_UNDOINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class UndoInterpreter: public ServerExpression {
public:
    UndoInterpreter(){};
    virtual ~UndoInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        Game *game = context->getGame();

        bool ret = game->Undo();
        context->setReply(ServerCommand::getBoolString(ret));
    }
};

}

#endif
