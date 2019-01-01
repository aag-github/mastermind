#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_SETPROPOSEDCOMBINATIONINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_SETPROPOSEDCOMBINATIONINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class SetProposedCombinationInterpreter: public ServerExpression {
public:
    SetProposedCombinationInterpreter(){};
    virtual ~SetProposedCombinationInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        Game *game = context->getGame();

        auto args = ServerCommand::splitArgs(context->getArgs());
        assert(args.size() == 2);
        Combination combination;
        combination = args[0];
        bool recordUndoEvent = ServerCommand::getBoolValue(args[1]);

        ProposedCombinationState state = game->setProposedCombination(combination, recordUndoEvent);

        std::string reply = ProposedCombinationStateMap::getStateString(state);
        context->setReply(reply);
    }
};

}

#endif
