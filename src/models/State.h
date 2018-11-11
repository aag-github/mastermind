#ifndef SRC_MODELS_STATE_H_
#define SRC_MODELS_STATE_H_

namespace Mastermind {

enum class State {
    INITIAL,
    READ_PROPOSED_COMBINATION,
    GAME_END,
    EXIT,
};

}

#endif
