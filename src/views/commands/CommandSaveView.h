#ifndef SRC_VIEWS_COMMANDS_COMMANDSAVEVIEW_H_
#define SRC_VIEWS_COMMANDS_COMMANDSAVEVIEW_H_

#include <commands/CommandView.h>

namespace Mastermind {

class CommandSaveView: public CommandView {
public:
    CommandSaveView(std::string title, State nextState) : CommandView(title, nextState) {};

    virtual ~CommandSaveView() {};
};

}

#endif
