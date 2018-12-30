#ifndef SRC_VIEWS_COMMANDS_COMMANDVIEW_H_
#define SRC_VIEWS_COMMANDS_COMMANDVIEW_H_

#include "State.h"

namespace Mastermind {

class MenuController;

class CommandView {
public:
    CommandView(std::string title, State nextState) :
        title(title),
        nextState(nextState),
        enabled(true)
    {

    };

    virtual ~CommandView(){};

    virtual void execute(MenuController *controller) {
        assert(controller != nullptr);

        controller->setNextState(nextState);
    }

    std::string getTitle() {
        return title;
    }

    bool isEnabled() {
        return enabled;
    }

    void setEnabled(bool b) {
        enabled = b;
    }

private:
    std::string title;

    State nextState;

    bool enabled;
};

}

#endif
