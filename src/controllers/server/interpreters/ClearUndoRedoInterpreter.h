#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_CLEARUNDOREDOINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_CLEARUNDOREDOINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class ClearUndoRedoInterpreter: public ServerExpression {
public:
    ClearUndoRedoInterpreter(){};
    virtual ~ClearUndoRedoInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        Game *game = context->getGame();

        game->clearUndoRedo();
        context->setReply(ServerCommand::getCommandString(ServerCommand::Command::OK));
    }
};

}

#endif
