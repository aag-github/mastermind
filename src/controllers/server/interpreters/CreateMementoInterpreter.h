#ifndef SRC_CONTROLLERS_SERVER_INTERPRETERS_CREATEMEMENTOINTERPRETER_H_
#define SRC_CONTROLLERS_SERVER_INTERPRETERS_CREATEMEMENTOINTERPRETER_H_

#include <server/ServerExpression.h>

namespace Mastermind {

class CreateMementoInterpreter: public ServerExpression {
public:
    CreateMementoInterpreter(){};
    virtual ~CreateMementoInterpreter(){};

    virtual void interpret(ServerInterpreterContext* context) override final {
        Game *game = context->getGame();
        std::shared_ptr<Memento> memento = game->createMemento();
        std::string args = std::to_string(memento->get().size());
        for(auto str : memento->get()) {
            std::cout << "-----------" << str;
            args = ServerCommand::concatArgs(args, str);
        }
        context->setReply(args);
    }
};

}

#endif
