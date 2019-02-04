#ifndef SRC_VIEWS_STARTMENUVIEW_H_
#define SRC_VIEWS_STARTMENUVIEW_H_

#include <vector>
#include <iostream>
#include "MenuView.h"
#include "CharReader.h"
#include "client/StartMenuController.h"
#include "ui/CommandView.h"
#include "ui/ShowMenuView.h"

#include "commands/QuitView.h"
#include "commands/StartView.h"
#include "commands/LoadGameView.h"

namespace Mastermind {

class StartMenuView : public MenuView<StartMenuController> {
public:
    StartMenuView() : MenuView() {
    };

    virtual ~StartMenuView(){
    };

    virtual void interact(StartMenuController* controller) override final {
        setCommands(controller);

        ShowMenuView showMenuView(&commands, "Pick an option");

        int option = showMenuView.execute();

        commands[option - 1]->execute();
    }

protected:
    QuitView quitView;

    StartView startView;

    LoadGameView loadGameView;

private:
    virtual void setCommands(StartMenuController* controller) override final {
        deleteCommands();

        commands.push_back(new CommandViewTemplate<StartView, StartController>(
                "Start", &startView, controller));
        commands.push_back(new CommandViewTemplate<LoadGameView, LoadGameController>(
                "Load", &loadGameView, controller));
        commands.push_back(new CommandViewTemplate<QuitView, QuitController>(
                "Quit", &quitView, controller));
    }


};

}

#endif
