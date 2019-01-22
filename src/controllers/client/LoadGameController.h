#ifndef SRC_CONTROLLERS_LOADGAMECONTROLLER_H_
#define SRC_CONTROLLERS_LOADGAMECONTROLLER_H_

#include "persistence/GameFilePersistence.h"
#include "ClientOperationController.h"

namespace Mastermind {

class LoadGameController: public Controller {
public:
    LoadGameController(Game &game) :
        Controller(game)
    {
    }

    virtual ~LoadGameController(){
    }

    GamePersistenceResult load(std::string name) {
        assert(game.getState() == State::MAIN_MENU || game.getState() == State::START_MENU);

        GamePersistenceResult ok = gameLoader.load(&game, name);

        if(game.getState() == State::START_MENU && ok == GamePersistenceResult::OK) {
            game.setState(State::MAIN_MENU);
        }

        return ok;
    }

    void noGamesAvailable() {
        assert(game.getState() == State::MAIN_MENU || game.getState() == State::START_MENU);
    }

    std::vector<std::string> getAvailableGames(){
        return gameLoader.getAvailableGames();
    }
private:
    GameFilePersistence gameLoader;
};

}

#endif
