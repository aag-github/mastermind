#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_CANUNDOINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_CANUNDOINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class CanUndoInterpreter: public ServerExpression {
public:
    CanUndoInterpreter(){};
    virtual ~CanUndoInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        Game *game = context->getGame();

        bool ret = game->canUndo();
        context->setReply(ServerCommand::getBoolString(ret));
    }
};

}

#endif
