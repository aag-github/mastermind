#ifndef SRC_VIEWS_MENUVIEW_H_
#define SRC_VIEWS_MENUVIEW_H_

#include <commands/ShowMenuView.h>
#include <vector>
#include <iostream>
#include "CharReader.h"
#include "MenuController.h"
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
    virtual void setCommands(bool undo, bool redo) {
        deleteCommands();

        commands.push_back(new OptionalCommandView("Undo", State::UNDO, undo));
        commands.push_back(new OptionalCommandView("Redo", State::REDO, redo));
        commands.push_back(new CommandView("Load", State::LOAD_GAME));
        commands.push_back(new CommandView("Save", State::SAVE_GAME));
        commands.push_back(new CommandView("Type new combination", State::READ_PROPOSED_COMBINATION));
        commands.push_back(new CommandView("Restart game", State::RESTART));
        commands.push_back(new CommandView("Quit", State::QUIT));
    }

    void interact(MenuController* controller) {
        ShowMenuView showMenuView(&commands);

        BoardView(&controller->getProposedCombinations(), &controller->getSecretCombination()).show(true);

        int option = showMenuView.execute();

        commands[option - 1]->execute(controller);
    }

    void build(bool undo, bool redo) {
        this->setCommands(undo, redo);
    }

protected:
    std::vector<CommandView*> commands;
};

}

#endif
