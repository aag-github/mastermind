#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_RESTOREMEMENTOINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_RESTOREMEMENTOINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class RestoreMementoInterpreter: public ServerExpression {
public:
    RestoreMementoInterpreter(){};
    virtual ~RestoreMementoInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        Game *game = context->getGame();

        auto args = ServerCommand::splitArgs(context->getArgs());
        assert(args.size() >= 2);

        std::shared_ptr<Memento> memento = std::make_shared<Memento>();
        for(size_t i = 1; i < args.size() - 1; i++) {
            memento->add(args[i]);
        }

        bool recordUndoEvent = ServerCommand::getBoolValue(args[args.size() - 1]);

        MementoRestoreResult result = game->restoreMemento(memento, recordUndoEvent);
        context->setReply(MementoRestoreResultMap::getMementoRestoreResultString(result));
   }
};

}

#endif
