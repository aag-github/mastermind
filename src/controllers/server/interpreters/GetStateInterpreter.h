#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_GETSTATEINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_GETSTATEINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class GetStateInterpreter: public ServerExpression {
public:
    GetStateInterpreter(){};
    virtual ~GetStateInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {

    }
};

}

#endif
