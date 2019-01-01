#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_REDOINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_REDOINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class RedoInterpreter: public ServerExpression {
public:
    RedoInterpreter(){};
    virtual ~RedoInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        Game *game = context->getGame();

        bool ret = game->Redo();
        context->setReply(ServerCommand::getBoolString(ret));
    }
};

}

#endif
