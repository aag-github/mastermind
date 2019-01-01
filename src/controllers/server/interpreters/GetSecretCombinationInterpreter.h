#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_GETSECRETCOMBINATIONINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_GETSECRETCOMBINATIONINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class GetSecretCombinationInterpreter: public ServerExpression {
public:
    GetSecretCombinationInterpreter(){};
    virtual ~GetSecretCombinationInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        Game *game = context->getGame();

        SecretCombination secret = game->getSecretCombination();
        context->setReply(secret.getString());
    }
};

}

#endif
