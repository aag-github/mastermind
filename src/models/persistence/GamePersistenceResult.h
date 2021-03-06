#ifndef SRC_MODELS_PERSISTENCE_GAMEPERSISTENCERESULT_H_
#define SRC_MODELS_PERSISTENCE_GAMEPERSISTENCERESULT_H_

namespace Mastermind {

enum class GamePersistenceResult {
    OK = 0,
    OPEN_FILE_ERROR,
    SECRET_COMBINATION_ERROR,
    PROPOSED_COMBINATION_ERROR,
};

}

#endif
