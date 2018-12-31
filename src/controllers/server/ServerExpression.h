#ifndef SRC_CONTROLLERS_SERVER_SERVEREXPRESSION_H_
#define SRC_CONTROLLERS_SERVER_SERVEREXPRESSION_H_

#include "ServerInterpreterContext.h"

namespace Mastermind {

class ServerExpression {
public:
    ServerExpression(){};
    virtual ~ServerExpression(){};

    virtual void interpret(ServerInterpreterContext* context) = 0;
};

}

#endif
