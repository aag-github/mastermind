#ifndef SRC_VIEWS_MENUVIEW_H_
#define SRC_VIEWS_MENUVIEW_H_

#include "ui/CommandView.h"

namespace Mastermind {

template <class CONTROLER_PROVIDER> class MenuView {
public:
    MenuView(){
    };

    virtual ~MenuView(){
        deleteCommands();
    };

    virtual void interact(CONTROLER_PROVIDER* controller) = 0;
protected:
    std::vector<CommandView*> commands;

    void deleteCommands() {
        for (auto command : commands ){
            delete command;
        }
        commands.clear();
    }

private:
    virtual void setCommands(CONTROLER_PROVIDER* controller) = 0 ;

};

}

#endif
