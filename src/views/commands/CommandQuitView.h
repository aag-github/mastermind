#ifndef SRC_VIEWS_COMMANDS_COMMANDEXITVIEW_H_
#define SRC_VIEWS_COMMANDS_COMMANDEXITVIEW_H_

#include <commands/CommandView.h>

namespace Mastermind {

class CommandQuitView: public CommandView {
public:
    CommandQuitView(std::string title, State nextState) : CommandView(title, nextState) {};

    virtual ~CommandQuitView() {};

};

}

#endif
