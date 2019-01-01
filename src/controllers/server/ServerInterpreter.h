#ifndef SRC_CONTROLLERS_SERVER_SERVERINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_SERVERINTERPRETER_H_

#include <memory>
#include "server/ServerCommand.h"
#include "ServerExpression.h"

namespace Mastermind {

class ServerInterpreter : public ServerExpression {
public:
    ServerInterpreter() {
        //TODO implement interpreter map
        //buildInterpreterPrototypes();
    }

    virtual ~ServerInterpreter() {
    }

    void interpret(ServerInterpreterContext* context) override final {
        context->setReply("");
        Game *game = context->getGame();
        switch(ServerCommand::getCommandId(context->getCommand()))
        {
        case ServerCommand::Command::GET_STATE:
            context->setReply(std::to_string(size_t(game->getState())));
            break;
        case ServerCommand::Command::SET_STATE:
            game->setState(StateMap::getState(atoi(context->getValue().c_str())));
            context->setReply(ServerCommand::getCommandString(ServerCommand::Command::OK));
            break;
        case ServerCommand::Command::GET_SECRET_COMBINATION: {
            SecretCombination secret = game->getSecretCombination();
            context->setReply(secret.getString());
            break;
        }
        case ServerCommand::Command::GET_PROPOSED_COMBINATIONS: {
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
            break;
        }
        case ServerCommand::Command::SET_SECRET_COMBINATION:
            assert(false);
            // TODO:
            break;
        case ServerCommand::Command::SET_PROPOSED_COMBINATION: {
            auto args = ServerCommand::splitArgs(context->getValue());
            assert(args.size() == 2);
            Combination combination;
            combination = args[0];
            bool recordUndoEvent = ServerCommand::getBoolValue(args[1]);

            ProposedCombinationState state = game->setProposedCombination(combination, recordUndoEvent);

            std::string reply = ProposedCombinationStateMap::getStateString(state);
            context->setReply(reply);
            break;
        }
        case ServerCommand::Command::START:
            game->start();
            context->setReply(ServerCommand::getCommandString(ServerCommand::Command::OK));
            break;
        case ServerCommand::Command::CAN_REDO: {
            bool ret = game->canRedo();
            context->setReply(ServerCommand::getBoolString(ret));
            break;
        }
        case ServerCommand::Command::CAN_UNDO: {
            bool ret = game->canUndo();
            context->setReply(ServerCommand::getBoolString(ret));
            break;
        }
        case ServerCommand::Command::REDO: {
            bool ret = game->Redo();
            context->setReply(ServerCommand::getBoolString(ret));
            break;
        }
        case ServerCommand::Command::UNDO: {
            bool ret = game->Undo();
            context->setReply(ServerCommand::getBoolString(ret));
            break;
        }
        case ServerCommand::Command::ADD_UNDO: {
            game->AddUndo();
            context->setReply(ServerCommand::getCommandString(ServerCommand::Command::OK));
            break;
        }
        case ServerCommand::Command::CLEAR_UNDO_REDO: {
            game->clearUndoRedo();
            context->setReply(ServerCommand::getCommandString(ServerCommand::Command::OK));
            break;
        }
        case ServerCommand::Command::CREATE_MEMENTO: {
            //TODO:
            assert(false);
            break;
        }
        case ServerCommand::Command::RESTORE_MEMENTO: {
            //TODO:
            assert(false);
            break;
        }
        case ServerCommand::Command::NONE:
        default:
            assert(false);
            break;
        }
    }

private:
    std::map<ServerCommand::Command, std::unique_ptr<ServerExpression>> interpreters;

/*    void buildInterpreterPrototypes() {
        interpreters[ServerCommand::Command::GET_STATE] = std::unique_ptr<GetStateInterpreter>(new GetStateInterpreter);
        SET_STATE,
        GET_SECRET_COMBINATION,
        GET_PROPOSED_COMBINATIONS,
        START,
        SET_PROPOSED_COMBINATION,
        SET_SECRET_COMBINATION,
        CREATE_MEMENTO,
        RESTORE_MEMENTO,
        ADD_UNDO,
        CAN_UNDO,
        CAN_REDO,
        UNDO,
        REDO,
        CLEAR_UNDO_REDO,
    }*/
};

}

#endif
