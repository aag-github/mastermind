#ifndef SRC_CONTROLLERS_SAVEGAMECONTROLLER_H_
#define SRC_CONTROLLERS_SAVEGAMECONTROLLER_H_

#include "persistence/GameFilePersistence.h"
#include "ClientOperationController.h"

namespace Mastermind {

class SaveGameController {
public:
    virtual ~SaveGameController() {};

    virtual GamePersistenceResult save(std::string name) = 0;

    virtual std::vector<std::string> getAvailableGames() = 0;
};

class SaveGameControllerImpl: public Controller, public SaveGameController{
public:
    SaveGameControllerImpl(Game &game) :
        Controller(game)
    {
    }

    virtual ~SaveGameControllerImpl(){
    }

    virtual GamePersistenceResult save(std::string name) override final {
        assert(game.getState() == State::MAIN_MENU);

        GamePersistenceResult ok = gameSaver.save(&game, name);

        game.setState(State::MAIN_MENU);

        return ok;
    }

    virtual std::vector<std::string> getAvailableGames() override final {
        return gameSaver.getAvailableGames();
    }

private:
    GameFilePersistence gameSaver;

};

}

#endif
