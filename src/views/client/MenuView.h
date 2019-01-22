#ifndef SRC_VIEWS_MENUVIEW_H_
#define SRC_VIEWS_MENUVIEW_H_

#include <ui/ShowMenuView.h>
#include <vector>
#include <iostream>
#include "CharReader.h"
#include "client/MenuController.h"
#include "ui/CommandView.h"
#include "ui/OptionalCommandView.h"

#include "ReadCombinationView.h"
#include "QuitView.h"
#include "RestartView.h"
#include "LoadGameView.h"
#include "SaveGameView.h"
#include "UndoView.h"
#include "RedoView.h"

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

        commands.push_back(new OptionalCommandView<UndoView, UndoController>(
                "Undo", &undoView, controller->getUndoController(), controller->getUndoController()->canUndo()));
        commands.push_back(new OptionalCommandView<RedoView, RedoController>(
                "Redo", &redoView, controller->getRedoController(), controller->getRedoController()->canRedo()));
        commands.push_back(new CommandViewTemplate<LoadGameView, LoadGameController>(
                "Load", &loadGameView, controller->getLoadGameController()));
        commands.push_back(new CommandViewTemplate<SaveGameView, SaveGameController>(
                "Save", &saveGameView, controller->getSaveGameController()));
        commands.push_back(new CommandViewTemplate<ReadCombinationView, ReadCombinationController>(
                "Type new combination", &readCombinationView, controller->getReadCombinationController()));
        commands.push_back(new CommandViewTemplate<RestartView, RestartController>(
                "Restart", &restartView, controller->getRestartController()));
        commands.push_back(new CommandViewTemplate<QuitView, QuitController>(
                "Quit", &quitView, controller->getQuitController()));
    }

    void interact(MenuController* controller) {
        setCommands(controller);

        ShowMenuView showMenuView(&commands,
                                  "Pick an option or press 'Enter' to type a new combination",
                                  5);

        BoardView(&controller->getProposedCombinations(), &controller->getSecretCombination()).show(true);

        int option = showMenuView.execute();

        commands[option - 1]->execute();
    }

protected:
    std::vector<CommandView*> commands;

    ReadCombinationView readCombinationView;

    QuitView quitView;

    RestartView restartView;

    LoadGameView loadGameView;

    SaveGameView saveGameView;

    UndoView undoView;

    RedoView redoView;
};

}

#endif
