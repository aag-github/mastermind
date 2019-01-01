#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_RESTOREMEMENTOINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_RESTOREMEMENTOINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class RestoreMementoInterpreter: public ServerExpression {
public:
    RestoreMementoInterpreter(){};
    virtual ~RestoreMementoInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        //Game *game = context->getGame();

        //TODO:
        assert(false);
    }
};

}

#endif
