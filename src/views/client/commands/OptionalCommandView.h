#ifndef SRC_VIEWS_COMMANDS_OPTIONALCOMMANDVIEW_H_
#define SRC_VIEWS_COMMANDS_OPTIONALCOMMANDVIEW_H_

#include "CommandView.h"

namespace Mastermind {

class MenuController;

class OptionalCommandView : public CommandView {
public:
    OptionalCommandView(std::string title, State nextState, bool enabled) :
        CommandView(title, nextState),
        enabled(enabled)
    {
    };

    virtual ~OptionalCommandView(){};

    virtual void show(std::string prefix) override final {
        if (enabled) {
            CommandView::show(prefix);
        } else {
            CommandView::show("*");
        }
    }
private:
    bool enabled;
};

}

#endif
