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
    virtual void setCommands() {
        deleteCommands();

        commands.push_back(new CommandUndoView("Undo", State::MENU));
        commands.push_back(new CommandRedoView("Redo", State::MENU));
        commands.push_back(new CommandLoadView("Load", State::MENU));
        commands.push_back(new CommandSaveView("Save", State::MENU));
        commands.push_back(new CommandContinueGameView("Type new combination", State::READ_PROPOSED_COMBINATION));
        commands.push_back(new CommandRestartGameView("Restart game", State::MENU));
        commands.push_back(new CommandQuitView("Quit", State::QUIT));
    }

    void interact(MenuController* controller) {
        int i = 1;
        std::cout << std::endl << "--------------" << std::endl;
        for(auto command : commands) {
            std::cout << i++ << ".- " << command->getTitle() << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Pick an option or press 'Enter' to type a new combination" << std::endl;

        IO::CharChecker charChecker("1234567\n");
        int option = IO::CharReader::read(&charChecker);
        if (option == '\n') {
            option = '5';
        }
        option = option - '0';
        commands[option - 1]->execute(controller);
    }

    void build() {
        this->setCommands();
    }

protected:
    std::vector<CommandView*> commands;
};

}

#endif
