#ifndef SRC_CONTROLLERS_SAVEGAMECONTROLLER_H_
#define SRC_CONTROLLERS_SAVEGAMECONTROLLER_H_

#include "persistence/GameFilePersistence.h"
#include "ClientOperationController.h"

namespace Mastermind {

class SaveGameController: public Controller {
public:
    SaveGameController(Game &game) :
        Controller(game)
    {
    }

    virtual ~SaveGameController(){
    }

    GamePersistenceResult save(std::string name) {
        assert(game.getState() == State::MAIN_MENU);

        GamePersistenceResult ok = gameSaver.save(&game, name);

        game.setState(State::MAIN_MENU);

        return ok;
    }

    std::vector<std::string> getAvailableGames(){
        return gameSaver.getAvailableGames();
    }

private:
    GameFilePersistence gameSaver;

};

}

#endif
