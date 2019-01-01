#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_SETSTATEINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_SETSTATEINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class SetStateInterpreter: public ServerExpression {
public:
    SetStateInterpreter(){};
    virtual ~SetStateInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        Game *game = context->getGame();

        game->setState(StateMap::getState(atoi(context->getArgs().c_str())));
        context->setReply(ServerCommand::getCommandString(ServerCommand::Command::OK));
    }
};

}

#endif
