#ifndef SRC_VIEWS_COMMANDS_COMMANDVIEW_H_
#define SRC_VIEWS_COMMANDS_COMMANDVIEW_H_

#include "State.h"

namespace Mastermind {

class MenuController;

class CommandView {
public:
    CommandView(std::string title, State nextState) :
        title(title),
        nextState(nextState)
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
private:
    std::string title;

    State nextState;
};

}

#endif
