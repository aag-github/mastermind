#ifndef SRC_VIEWS_MENUVIEW_H_
#define SRC_VIEWS_MENUVIEW_H_

#include <client/commands/ShowMenuView.h>
#include <vector>
#include <iostream>
#include "CharReader.h"
#include "client/MenuController.h"
#include "commands/CommandView.h"
#include "commands/OptionalCommandView.h"

namespace Mastermind {

class MenuView {
public:
    MenuView(){
    };

    virtual ~MenuView(){
        deleteCommands();
    };

    void deleteCommands() {
        for (auto command : commands ){
            delete command;
        }
        commands.clear();
    }
    virtual void setCommands(MenuController* controller) {
        deleteCommands();

        commands.push_back(new OptionalCommandView("Undo", State::UNDO, controller->canUndo()));
        commands.push_back(new OptionalCommandView("Redo", State::REDO, controller->canRedo()));
        commands.push_back(new CommandView("Load", State::LOAD_GAME));
        commands.push_back(new CommandView("Save", State::SAVE_GAME));
        commands.push_back(new CommandView("Type new combination", State::READ_PROPOSED_COMBINATION));
        commands.push_back(new CommandView("Restart game", State::RESTART));
        commands.push_back(new CommandView("Quit", State::QUIT));
    }

    void interact(MenuController* controller) {
        setCommands(controller);

        ShowMenuView showMenuView(&commands);

        BoardView(&controller->getProposedCombinations(), &controller->getSecretCombination()).show(true);

        int option = showMenuView.execute();

        commands[option - 1]->execute(controller);
    }

protected:
    std::vector<CommandView*> commands;
};

}

#endif
