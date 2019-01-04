#ifndef SRC_MODELS_STATE_H_
#define SRC_MODELS_STATE_H_

#include <assert.h>
#include <unordered_map>

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

class StateMap {
public:
    static State getState(int stateId){
        auto item = stateMap.find(stateId);
        assert(item != stateMap.end());
        return item->second;
    }

    size_t getStateId(State state){
        return size_t(state);
    }

private:
    static std::unordered_map<int, State> stateMap ;
};

}

#endif
