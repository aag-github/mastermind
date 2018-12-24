#ifndef SRC_VIEWS_COMMANDS_COMMANDREDOVIEW_H_
#define SRC_VIEWS_COMMANDS_COMMANDREDOVIEW_H_

#include <commands/CommandView.h>

namespace Mastermind {

class CommandRedoView : public CommandView {
public:
    CommandRedoView(std::string title, State nextState) : CommandView(title, nextState) {};

    virtual ~CommandRedoView() {};
};

}

#endif
