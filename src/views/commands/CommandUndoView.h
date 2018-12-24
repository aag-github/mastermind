#ifndef SRC_VIEWS_COMMANDS_COMMANDUNDOVIEW_H_
#define SRC_VIEWS_COMMANDS_COMMANDUNDOVIEW_H_

namespace Mastermind {

class CommandUndoView : public CommandView {
public:
    CommandUndoView(std::string title, State nextState) : CommandView(title, nextState) {};

    virtual ~CommandUndoView() {};
};

}

#endif
