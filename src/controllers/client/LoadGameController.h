#ifndef SRC_CONTROLLERS_LOADGAMECONTROLLER_H_
#define SRC_CONTROLLERS_LOADGAMECONTROLLER_H_

#include "persistence/GameFilePersistence.h"
#include "ClientOperationController.h"

namespace Mastermind {

class LoadGameController: public ClientOperationController {
public:
    LoadGameController(Game &game) :
        ClientOperationController(game)
    {
    }

    virtual ~LoadGameController(){
    }

    GamePersistenceResult load(std::string name) {
        assert(game.getState() == State::MAIN_MENU);

        GamePersistenceResult ok = gameLoader.load(&game, name);

        game.setState(State::MAIN_MENU);

        return ok;
    }

    void noGamesAvailable() {
        assert(game.getState() == State::MAIN_MENU);

        game.setState(State::MAIN_MENU);
    }

    std::vector<std::string> getAvailableGames(){
        return gameLoader.getAvailableGames();
    }

    virtual void accept(ClientOperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };
private:
    GameFilePersistence gameLoader;
};

}

#endif
