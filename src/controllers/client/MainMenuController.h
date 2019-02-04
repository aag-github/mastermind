#ifndef SRC_CONTROLLERS_MENUCONTROLLER_H_
#define SRC_CONTROLLERS_MENUCONTROLLER_H_

#include <assert.h>
#include "CombinationController.h"

#include "ReadCombinationController.h"
#include "QuitController.h"
#include "RestartController.h"
#include "LoadGameController.h"
#include "SaveGameController.h"
#include "UndoController.h"
#include "RedoController.h"

namespace Mastermind {

class MainMenuController: public ClientOperationController,
                      public QuitController,
                      public UndoController,
                      public RedoController,
                      public RestartController,
                      public SaveGameController,
                      public ReadCombinationController
{
public:
    MainMenuController(Game &game) :
        ClientOperationController(game),
        readCombinationController(game),
        quitController(game),
        restartController(game),
        saveGameController(game),
        undoController(game),
        redoController(game)
    {
    }

    virtual ~MainMenuController(){
    }

    virtual void accept(ClientOperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

    virtual void quit(bool quit) override final {
        quitController.quit(quit);
    }

    virtual void undo() override final {
        undoController.undo();
    }

    virtual bool canUndo() override final {
        return undoController.canUndo();
    }

    virtual void redo() override final {
        redoController.redo();
    }

    virtual bool canRedo() override final {
        return redoController.canRedo();
    }

    virtual void restart() override final {
        restartController.restart();
    }

    virtual GamePersistenceResult save(std::string name) override final {
        return saveGameController.save(name);
    }

    virtual std::vector<std::string> getAvailableGames() override final {
        return saveGameController.getAvailableGames();
    }

    virtual void gameEnd(bool end) override final {
        readCombinationController.gameEnd(end);
    }

    virtual ProposedCombinationState setProposedCombination (const Combination& proposedCombination) override final {
        return readCombinationController.setProposedCombination(proposedCombination);
    }

    virtual const ProposedCombinationList& getProposedCombinations() const {
        return readCombinationController.getProposedCombinations();
    }

    virtual const SecretCombination& getSecretCombination() const {
        return readCombinationController.getSecretCombination();
    }

private:
    ReadCombinationControllerImpl readCombinationController;

    QuitControllerImpl quitController;

    RestartControllerImpl restartController;

    SaveGameControllerImpl saveGameController;

    UndoControllerImpl undoController;

    RedoControllerImpl redoController;
};

}

#endif
