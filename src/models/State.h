#ifndef SRC_MODELS_STATE_H_
#define SRC_MODELS_STATE_H_

namespace Mastermind {

enum class State {
    INITIAL,
    MENU,
    READ_PROPOSED_COMBINATION,
    GAME_END,
    QUIT,
    RESTART,
    LOAD_GAME,
    SAVE_GAME,
    UNDO,
    REDO,
    EXIT,
};

}

#endif