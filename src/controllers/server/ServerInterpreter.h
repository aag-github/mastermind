#ifndef SRC_CONTROLLERS_SERVER_SERVERINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_SERVERINTERPRETER_H_

#include <server/ServerCommand.h>
#include "ServerExpression.h"

namespace Mastermind {

class ServerInterpreter : public ServerExpression {
public:
    ServerInterpreter() {}

    virtual ~ServerInterpreter() {}

    void interpret(ServerInterpreterContext* context) override final {
        context->setReply("");
        std::cout << "hello";
        Game *game = context->getGame();
        switch(ServerCommandMap::getCommandId(context->getCommand()))
        {
        case ServerCommand::GET_STATE:;
            context->setReply(std::to_string(size_t(game->getState())));
            break;
        case ServerCommand::SET_STATE:
            game->setState(StateMap::getState(atoi(context->getValue().c_str())));
            context->setReply("OK");
            break;
        case ServerCommand::NONE:
        default:
            assert(false);
            break;
        }
    }

};

}

#endif
