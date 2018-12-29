#ifndef SRC_MODELS_PERSISTENCE_GAMEPERSISTENCE_H_
#define SRC_MODELS_PERSISTENCE_GAMEPERSISTENCE_H_

#include <vector>
#include <string>
#include "GamePersistenceImpl.h"

namespace Mastermind {

class Game;

class GamePersistence {
public:
    virtual ~GamePersistence() {
        delete implementation;
    }

    virtual std::vector<std::string> getAvailableGames() const {
        return implementation->getAvailableGames();
    }

    virtual int load(Game* game, const std::string& name) {
        return implementation->load(game, name);
    }

    int save(const Game* game, const std::string& name) const {
        return implementation->save(game, name);
    };

protected:
    GamePersistence() {
        implementation = nullptr;
    }

    GamePersistenceImpl *implementation;

private:
    GamePersistenceImpl* create();
};

}

#endif
