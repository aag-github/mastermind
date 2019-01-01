#ifndef SRC_CONTROLLERS_SERVER_SERVERINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_SERVERINTERPRETER_H_

#include <server/interpreters/CanRedoInterpreter.h>
#include <memory>
#include "server/ServerCommand.h"
#include "ServerExpression.h"
#include "interpreters/AddUndoInterpreter.h"
#include "interpreters/CanUndoInterpreter.h"
#include "interpreters/ClearUndoRedoInterpreter.h"
#include "interpreters/CreateMementoInterpreter.h"
#include "interpreters/GetProposedCombinationsInterpreter.h"
#include "interpreters/GetSecretCombinationInterpreter.h"
#include "interpreters/GetStateInterpreter.h"
#include "interpreters/RedoInterpreter.h"
#include "interpreters/RestoreMementoInterpreter.h"
#include "interpreters/SetProposedCombinationInterpreter.h"
#include "interpreters/SetSecretCombinationInterpreter.h"
#include "interpreters/StartInterpreter.h"
#include "interpreters/SetStateInterpreter.h"
#include "interpreters/UndoInterpreter.h"

namespace Mastermind {

class ServerInterpreter : public ServerExpression {
public:
    ServerInterpreter() {
        buildInterpreterPrototypes();
    }

    virtual ~ServerInterpreter() {
    }

    void interpret(ServerInterpreterContext* context) override final {
        context->setReply("");
        auto interpreter = this->interpreters.find(ServerCommand::getCommandId(context->getCommand()));
        assert(interpreter != interpreters.end() && interpreter->second != nullptr);

        interpreter->second->interpret(context);
    }

private:
    std::map<ServerCommand::Command, std::shared_ptr<ServerExpression>> interpreters;

    void buildInterpreterPrototypes() {
        interpreters[ServerCommand::Command::GET_STATE] = std::shared_ptr<GetStateInterpreter>(new GetStateInterpreter());
        interpreters[ServerCommand::Command::SET_STATE] = std::shared_ptr<SetStateInterpreter>(new SetStateInterpreter());
        interpreters[ServerCommand::Command::GET_SECRET_COMBINATION] = std::shared_ptr<GetSecretCombinationInterpreter>(new GetSecretCombinationInterpreter);
        interpreters[ServerCommand::Command::GET_PROPOSED_COMBINATIONS] = std::shared_ptr<GetProposedCombinationsInterpreter>(new GetProposedCombinationsInterpreter);
        interpreters[ServerCommand::Command::START] = std::shared_ptr<StartInterpreter>(new StartInterpreter);
        interpreters[ServerCommand::Command::SET_PROPOSED_COMBINATION] = std::shared_ptr<SetProposedCombinationInterpreter>(new SetProposedCombinationInterpreter);
        interpreters[ServerCommand::Command::SET_SECRET_COMBINATION] = std::shared_ptr<SetSecretCombinationInterpreter>(new SetSecretCombinationInterpreter);
        interpreters[ServerCommand::Command::CREATE_MEMENTO] = std::shared_ptr<CreateMementoInterpreter>(new CreateMementoInterpreter);
        interpreters[ServerCommand::Command::RESTORE_MEMENTO] = std::shared_ptr<RestoreMementoInterpreter>(new RestoreMementoInterpreter);
        interpreters[ServerCommand::Command::ADD_UNDO] = std::shared_ptr<AddUndoInterpreter>(new AddUndoInterpreter);
        interpreters[ServerCommand::Command::CAN_UNDO] = std::shared_ptr<CanUndoInterpreter>(new CanUndoInterpreter);
        interpreters[ServerCommand::Command::CAN_REDO] = std::shared_ptr<CanRedoInterpreter>(new CanRedoInterpreter);
        interpreters[ServerCommand::Command::UNDO] = std::shared_ptr<UndoInterpreter>(new UndoInterpreter);
        interpreters[ServerCommand::Command::REDO] = std::shared_ptr<RedoInterpreter>(new RedoInterpreter);
        interpreters[ServerCommand::Command::CLEAR_UNDO_REDO] = std::shared_ptr<ClearUndoRedoInterpreter>(new ClearUndoRedoInterpreter);
    }
};

}

#endif
