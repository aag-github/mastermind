#ifndef SRC_CONTROLLERS_LOADGAMECONTROLLER_H_
#define SRC_CONTROLLERS_LOADGAMECONTROLLER_H_

#include "persistence/GameFilePersistence.h"
#include "OperationController.h"

namespace Mastermind {

class LoadGameController: public OperationController {
public:
    LoadGameController(Game &game) :
        OperationController(game)
    {
    }

    virtual ~LoadGameController(){
    }

    int load(std::string name) {
        assert(game.getState() == State::LOAD_GAME);

        int ok = gameLoader.load(&game, name);

        game.setState((ok == 0) ? State::READ_PROPOSED_COMBINATION : State::MENU);

        return ok;
    }

    void noGamesAvailable() {
        game.setState(State::MENU);
    }

    std::vector<std::string> getAvailableGames(){
        return gameLoader.getAvailableGames();
    }

    virtual void accept(OperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };
private:
    GameFilePersistence gameLoader;
};

}

#endif
