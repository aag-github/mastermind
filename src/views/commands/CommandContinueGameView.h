#ifndef SRC_VIEWS_COMMANDS_COMMANDCOMBINATIONVIEW_H_
#define SRC_VIEWS_COMMANDS_COMMANDCOMBINATIONVIEW_H_

#include <commands/CommandView.h>
#include "State.h"

namespace Mastermind {

class CommandContinueGameView: public CommandView {
public:
    CommandContinueGameView(std::string title, State nextState) : CommandView(title, nextState) {};

    virtual ~CommandContinueGameView() {};
};

}

#endif
