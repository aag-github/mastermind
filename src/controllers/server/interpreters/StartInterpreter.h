#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_STARTINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_STARTINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class StartInterpreter: public ServerExpression {
public:
    StartInterpreter(){};
    virtual ~StartInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        Game *game = context->getGame();

        game->start();
        context->setReply(ServerCommand::getCommandString(ServerCommand::Command::OK));
    }
};

}

#endif
