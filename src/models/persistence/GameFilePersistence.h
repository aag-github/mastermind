#ifndef SRC_MODELS_PERSISTENCE_GAMEFILEPERSISTENCE_H_
#define SRC_MODELS_PERSISTENCE_GAMEFILEPERSISTENCE_H_

#include <persistence/GamePersistence.h>
#include <persistence/GameFilePersistenceImpl.h>

namespace Mastermind {

class GameFilePersistence: public GamePersistence {
public:
    GameFilePersistence() : GamePersistence() {
        implementation = new GameFilePersistenceImpl();
    };

    virtual ~GameFilePersistence() {};
};

}

#endif
