#ifndef SRC_VIEWS_MENUVIEW_H_
#define SRC_VIEWS_MENUVIEW_H_

#include "ui/CommandView.h"

namespace Mastermind {

template <class CONTROLLER_PROVIDER> class MenuView {
public:
    MenuView(){
        defaultCommand = nullptr;
    };

    virtual ~MenuView(){
        deleteCommands();
    };

    virtual void interact(CONTROLLER_PROVIDER* controller) = 0;
protected:
    std::vector<CommandView*> commands;

    CommandView* defaultCommand;

    void deleteCommands() {
        for (auto command : commands ){
            delete command;
        }
        commands.clear();
    }

private:
    virtual void setCommands(CONTROLLER_PROVIDER* controller) = 0 ;

};

}

#endif
