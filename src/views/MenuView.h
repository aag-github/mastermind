#ifndef SRC_VIEWS_MENUVIEW_H_
#define SRC_VIEWS_MENUVIEW_H_

#include <vector>
#include <iostream>
#include "CharReader.h"
#include "MenuController.h"
#include "commands/CommandView.h"
#include "commands/CommandUndoView.h"
#include "commands/CommandRedoView.h"
#include "commands/CommandLoadView.h"
#include "commands/CommandSaveView.h"
#include "commands/CommandContinueGameView.h"
#include "commands/CommandRestartGameView.h"
#include "commands/CommandQuitView.h"
#include "ui/ShowMenuView.h"

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

        commands.push_back(new CommandUndoView("Undo", State::UNDO));
        commands.back()->setEnabled(undo);
        commands.push_back(new CommandRedoView("Redo", State::REDO));
        commands.back()->setEnabled(redo);
        commands.push_back(new CommandLoadView("Load", State::LOAD_GAME));
        commands.push_back(new CommandSaveView("Save", State::SAVE_GAME));
        commands.push_back(new CommandContinueGameView("Type new combination", State::READ_PROPOSED_COMBINATION));
        commands.push_back(new CommandRestartGameView("Restart game", State::RESTART));
        commands.push_back(new CommandQuitView("Quit", State::QUIT));
    }

    void interact(MenuController* controller) {
        ShowMenuView showMenuView(&commands);

        BoardView(&controller->getProposedCombinations(), &controller->getSecretCombination()).show(true);

        showMenuView.show();

        int option = showMenuView.read();

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
