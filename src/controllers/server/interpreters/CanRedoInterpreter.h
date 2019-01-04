#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_CANREDOINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_CANREDOINTERPRETER_H_

#include <server/ServerExpression.h>
#include <server/ServerCommand.h>

namespace Mastermind {

class CanRedoInterpreter: public ServerExpression {
public:
    CanRedoInterpreter(){};
    virtual ~CanRedoInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        Game *game = context->getGame();

        bool ret = game->canRedo();
        context->setReply(ServerCommand::getBoolString(ret));
    }
};

}

#endif
