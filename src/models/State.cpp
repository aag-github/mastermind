#include "State.h"

namespace Mastermind {

std::unordered_map<int, State> StateMap::stateMap = {
        {0, State::START_MENU},
        {1, State::MAIN_MENU},
        {2, State::EXIT},
};

}


