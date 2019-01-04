#include "State.h"

namespace Mastermind {

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


