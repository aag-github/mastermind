#ifndef SRC_MODELS_PERSISTENCE_GAMEPERSISTENCEIMPL_H_
#define SRC_MODELS_PERSISTENCE_GAMEPERSISTENCEIMPL_H_

namespace Mastermind {

class Game;

class GamePersistenceImpl {
public:
    GamePersistenceImpl() {};

    virtual ~GamePersistenceImpl() {};

    virtual std::vector<std::string> getAvailableGames() const = 0;

    virtual int load(Game* game, const std::string& name) = 0;

    virtual int save(const Game* game, const std::string& name) const = 0;
};

}

#endif
