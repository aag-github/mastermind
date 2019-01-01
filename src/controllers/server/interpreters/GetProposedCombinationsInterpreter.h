#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_GETPROPOSEDCOMBINATIONSINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_GETPROPOSEDCOMBINATIONSINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class GetProposedCombinationsInterpreter: public ServerExpression {
public:
    GetProposedCombinationsInterpreter(){};
    virtual ~GetProposedCombinationsInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        Game *game = context->getGame();

        ProposedCombinationList combinations = game->getProposedCombinations();
        std::string reply = "";
        int count = 0;
        for(auto combination : combinations) {
            if(combination.isSet()) {
                count++;
                reply = ServerCommand::addListElement(reply, combination.getString());
            }
        }
        reply = ServerCommand::addListElement(std::to_string(count), reply);
        context->setReply(reply);
    }
};

}

#endif
