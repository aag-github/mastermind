#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_GETUNDOINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_GETUNDOINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class AddUndoInterpreter: public ServerExpression {
public:
    AddUndoInterpreter(){};
    virtual ~AddUndoInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        Game *game = context->getGame();

        game->AddUndo();
        context->setReply(ServerCommand::getCommandString(ServerCommand::Command::OK));
    }
};

}

#endif
