#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_SETSECRETCOMBINATIONINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_SETSECRETCOMBINATIONINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class SetSecretCombinationInterpreter: public ServerExpression {
public:
    SetSecretCombinationInterpreter(){};
    virtual ~SetSecretCombinationInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        Game *game = context->getGame();

        auto args = ServerCommand::splitArgs(context->getArgs());
        assert(args.size() == 2);
        SecretCombination combination;
        combination = args[0];
        bool recordUndoEvent = ServerCommand::getBoolValue(args[1]);

        game->setSecretCombination(combination, recordUndoEvent);

        context->setReply(ServerCommand::getCommandString(ServerCommand::Command::OK));
    }
};

}

#endif
