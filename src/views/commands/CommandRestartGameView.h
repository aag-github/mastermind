#ifndef SRC_VIEWS_COMMANDS_COMMANDRESTARTGAMEVIEW_H_
#define SRC_VIEWS_COMMANDS_COMMANDRESTARTGAMEVIEW_H_

#include <commands/CommandView.h>

namespace Mastermind {

class CommandRestartGameView: public CommandView {
public:
    CommandRestartGameView(std::string title, State nextState) : CommandView(title, nextState) {};

    virtual ~CommandRestartGameView() {};
};

}

#endif
