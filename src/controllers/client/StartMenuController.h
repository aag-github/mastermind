#ifndef SRC_CONTROLLERS_STARTMENUCONTROLLER_H_
#define SRC_CONTROLLERS_STARTMENUCONTROLLER_H_

#include <assert.h>
#include "CombinationController.h"

#include "CommonMenuController.h"

#include "StartController.h"
#include "LoadGameController.h"

namespace Mastermind {

class StartMenuController: public ClientOperationController,
                           public CommonMenuController,
                           public StartController,
                           public LoadGameController
{
public:
    StartMenuController(Game &game) :
        ClientOperationController(game),
        CommonMenuController(game),
        startController(game),
        loadGameController(game)
    {
    }

    virtual ~StartMenuController(){
    }

    virtual void accept(ClientOperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

    virtual GamePersistenceResult load(std::string name) override final {
        return loadGameController.load(name);
    }

    virtual void noGamesAvailable() override final {
        loadGameController.noGamesAvailable();
    }

    virtual std::vector<std::string> getAvailableGames() override final {
        return loadGameController.getAvailableGames();
    }

    virtual void start() override final {
        startController.start();
    }
private:
    StartControllerImpl startController;

    LoadGameControllerImpl loadGameController;
};

}

#endif
