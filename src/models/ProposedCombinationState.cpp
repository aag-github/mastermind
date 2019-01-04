#include "ProposedCombinationState.h"

namespace Mastermind {

std::map<ProposedCombinationState, std::string> ProposedCombinationStateMap::map = {
        { ProposedCombinationState::NONE, "0" },
        { ProposedCombinationState::CONTINUE, "1" },
        { ProposedCombinationState::WIN, "2" },
        { ProposedCombinationState::LOSE, "3" },
};

}
