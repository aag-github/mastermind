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
private:
    static std::unordered_map<int, State> stateMap ;
};

std::unordered_map<int, State> StateMap::stateMap = {
        {0, State::INITIAL},
        {1, State::MENU},
        {2, State::READ_PROPOSED_COMBINATION},
        {3, State::GAME_END},
        {4, State::QUIT},
        {5, State::RESTART},
        {6, State::LOAD_GAME},
        {7, State::SAVE_GAME},
        {8, State::UNDO},
        {9, State::REDO},
        {10, State::EXIT},
};
}

#endif
