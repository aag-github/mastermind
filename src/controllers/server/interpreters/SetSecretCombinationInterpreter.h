#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_SETSECRETCOMBINATIONINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_SETSECRETCOMBINATIONINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class SetSecretCombinationInterpreter: public ServerExpression {
public:
    SetSecretCombinationInterpreter(){};
    virtual ~SetSecretCombinationInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        //Game *game = context->getGame();
//TODO;
        assert(false);
    }
};

}

#endif
