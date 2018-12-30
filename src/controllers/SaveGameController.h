#ifndef SRC_CONTROLLERS_SAVEGAMECONTROLLER_H_
#define SRC_CONTROLLERS_SAVEGAMECONTROLLER_H_

#include "persistence/GameFilePersistence.h"
#include "OperationController.h"

namespace Mastermind {

class SaveGameController: public OperationController {
public:
    SaveGameController(Game &game) :
        OperationController(game)
    {
    }

    virtual ~SaveGameController(){
    }

    int save(std::string name) {
        assert(game.getState() == State::SAVE_GAME);

        int ok = gameSaver.save(&game, name);

        game.setState(State::MENU);

        return ok;
    }

    std::vector<std::string> getAvailableGames(){
        return gameSaver.getAvailableGames();
    }

    virtual void accept(OperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

private:
    GameFilePersistence gameSaver;

};

}

#endif
