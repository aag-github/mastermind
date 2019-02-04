#ifndef SRC_VIEWS_MAINMENUVIEW_H_
#define SRC_VIEWS_MAINMENUVIEW_H_

#include <client/MainMenuController.h>
#include <vector>
#include <iostream>

#include "MenuView.h"
#include "CharReader.h"
#include "ui/CommandView.h"
#include "ui/OptionalCommandView.h"

#include "commands/ReadCombinationView.h"
#include "commands/QuitView.h"
#include "commands/RestartView.h"
#include "commands/LoadGameView.h"
#include "commands/SaveGameView.h"
#include "commands/UndoView.h"
#include "commands/RedoView.h"

#include "ui/ShowMenuView.h"

namespace Mastermind {

class MainMenuView : public MenuView<MainMenuController> {
public:
    MainMenuView() : MenuView() {
    };

    virtual ~MainMenuView(){
    };

    virtual void interact(MainMenuController* controller) override final {
        setCommands(controller);

        ShowMenuView showMenuView(&commands,
                                  "Pick an option or press 'Enter' to type a new combination",
                                  defaultCommand);

        BoardView(&controller->getProposedCombinations(), &controller->getSecretCombination()).show(true);

        int option = showMenuView.execute();

        commands[option - 1]->execute();
    }

private:
    ReadCombinationView readCombinationView;

    QuitView quitView;

    RestartView restartView;

    LoadGameView loadGameView;

    SaveGameView saveGameView;

    UndoView undoView;

    RedoView redoView;

    virtual void setCommands(MainMenuController* controller) override {
        deleteCommands();

        commands.push_back(new OptionalCommandView<UndoView, UndoController>(
                "Undo", &undoView, controller, controller->canUndo()));
        commands.push_back(new OptionalCommandView<RedoView, RedoController>(
                "Redo", &redoView, controller, controller->canRedo()));
        commands.push_back(new CommandViewTemplate<SaveGameView, SaveGameController>(
                "Save", &saveGameView, controller));

        commands.push_back(new CommandViewTemplate<ReadCombinationView, ReadCombinationController>(
                "Enter new combination", &readCombinationView, controller));
        defaultCommand = commands.back();

        commands.push_back(new CommandViewTemplate<RestartView, RestartController>(
                "Restart", &restartView, controller));
        commands.push_back(new CommandViewTemplate<QuitView, QuitController>(
                "Quit", &quitView, controller));
    }
};

}

#endif
