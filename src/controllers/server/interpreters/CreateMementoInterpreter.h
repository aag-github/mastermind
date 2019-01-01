#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_CREATEMEMENTOINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_CREATEMEMENTOINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class CreateMementoInterpreter: public ServerExpression {
public:
    CreateMementoInterpreter(){};
    virtual ~CreateMementoInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        //Game *game = context->getGame();

        //TODO:
        assert(false);
    }
};

}

#endif
