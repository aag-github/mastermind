#ifndef SRC_CONTROLLERS_LOADGAMECONTROLLER_H_
#define SRC_CONTROLLERS_LOADGAMECONTROLLER_H_

#include "persistence/GameFilePersistence.h"
#include "OperationController.h"

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
        assert(game.getState() == State::LOAD_GAME);

        GamePersistenceResult ok = gameLoader.load(&game, name);

        game.setState(State::MENU);

        return ok;
    }

    void noGamesAvailable() {
        assert(game.getState() == State::LOAD_GAME);

        game.setState(State::MENU);
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
