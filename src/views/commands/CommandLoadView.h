#ifndef SRC_VIEWS_COMMANDS_COMMANDLOADVIEW_H_
#define SRC_VIEWS_COMMANDS_COMMANDLOADVIEW_H_

#include <commands/CommandView.h>

namespace Mastermind {

class CommandLoadView: public CommandView {
public:
    CommandLoadView(std::string title, State nextState) : CommandView(title, nextState) {};

    virtual ~CommandLoadView() {};
};

}

#endif
