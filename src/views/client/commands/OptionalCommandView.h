#ifndef SRC_VIEWS_COMMANDS_OPTIONALCOMMANDVIEW_H_
#define SRC_VIEWS_COMMANDS_OPTIONALCOMMANDVIEW_H_

#include "CommandView.h"

namespace Mastermind {

class MenuController;

template <class VIEW, class CONTROLLER> class OptionalCommandView : public CommandViewTemplate<VIEW, CONTROLLER> {
public:
    OptionalCommandView(std::string title, VIEW *view, CONTROLLER *controller, bool enabled) :
        CommandViewTemplate<VIEW, CONTROLLER>(title, view, controller),
        enabled(enabled)
    {
    };

    virtual ~OptionalCommandView(){};

    virtual void show(std::string prefix) override final {
        if (enabled) {
            CommandViewTemplate<VIEW, CONTROLLER>::show(prefix);
        } else {
            CommandViewTemplate<VIEW, CONTROLLER>::show("*");
        }
    }
private:
    bool enabled;
};

}

#endif
