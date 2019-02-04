#ifndef SRC_CONTROLLERS_LOADGAMECONTROLLER_H_
#define SRC_CONTROLLERS_LOADGAMECONTROLLER_H_

#include "persistence/GameFilePersistence.h"
#include "ClientOperationController.h"

namespace Mastermind {

class LoadGameController {
public:
    virtual ~ LoadGameController(){};

    virtual GamePersistenceResult load(std::string name) = 0;

    virtual void noGamesAvailable() = 0;

    virtual std::vector<std::string> getAvailableGames() = 0;
};

class LoadGameControllerImpl: public Controller, public LoadGameController {
public:
    LoadGameControllerImpl(Game &game) :
        Controller(game)
    {
    }

    virtual ~LoadGameControllerImpl(){
    }

    virtual GamePersistenceResult load(std::string name) override final {
        assert(game.getState() == State::MAIN_MENU || game.getState() == State::START_MENU);

        GamePersistenceResult ok = gameLoader.load(&game, name);

        if(game.getState() == State::START_MENU && ok == GamePersistenceResult::OK) {
            game.setState(State::MAIN_MENU);
        }

        return ok;
    }

    virtual void noGamesAvailable() override final {
        assert(game.getState() == State::MAIN_MENU || game.getState() == State::START_MENU);
    }

    virtual std::vector<std::string> getAvailableGames() override final {
        return gameLoader.getAvailableGames();
    }
private:
    GameFilePersistence gameLoader;
};

}

#endif
