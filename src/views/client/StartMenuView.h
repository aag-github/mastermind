#ifndef SRC_VIEWS_STARTMENUVIEW_H_
#define SRC_VIEWS_STARTMENUVIEW_H_

#include <ui/ShowMenuView.h>
#include <vector>
#include <iostream>
#include "CharReader.h"
#include "client/StartMenuController.h"
#include "commands/CommandView.h"

#include "QuitView.h"
#include "StartView.h"
#include "LoadGameView.h"

namespace Mastermind {

class StartMenuView {
public:
    StartMenuView(){
    };

    virtual ~StartMenuView(){
        deleteCommands();
    };

    void deleteCommands() {
        for (auto command : commands ){
            delete command;
        }
        commands.clear();
    }
    virtual void setCommands(StartMenuController* controller) {
        deleteCommands();

        commands.push_back(new CommandViewTemplate<StartView, StartController>(
                "Start game", &startView, controller->getStartController()));
        commands.push_back(new CommandViewTemplate<LoadGameView, LoadGameController>(
                "Load", &loadGameView, controller->getLoadGameController()));
        commands.push_back(new CommandViewTemplate<QuitView, QuitController>(
                "Quit", &quitView, controller->getQuitController()));
    }

    void interact(StartMenuController* controller) {
        setCommands(controller);

        ShowMenuView showMenuView(&commands, "Pick an option");

        int option = showMenuView.execute();

        commands[option - 1]->execute();
    }

protected:
    std::vector<CommandView*> commands;

    QuitView quitView;

    StartView startView;

    LoadGameView loadGameView;
};

}

#endif
