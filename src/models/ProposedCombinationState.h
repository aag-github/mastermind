#ifndef SRC_MODELS_PROPOSEDCOMBINATIONSTATE_H_
#define SRC_MODELS_PROPOSEDCOMBINATIONSTATE_H_

#include <map>

namespace Mastermind
{

enum class ProposedCombinationState {
    NONE,
    CONTINUE,
    WIN,
    LOSE
};

class ProposedCombinationStateMap {
public:
    static std::string getStateString(ProposedCombinationState state){
        auto item = map.find(state);
        assert(item != map.end());
        return item->second;
    }

    static ProposedCombinationState getStateId(std::string state){
        for(auto &item : map) {
            if(item.second == state) {
                return item.first;
            }
        }
        assert(false);
        return ProposedCombinationState::NONE;
    }

private:
    static std::map<ProposedCombinationState, std::string> map ;
};

std::map<ProposedCombinationState, std::string> ProposedCombinationStateMap::map = {
        { ProposedCombinationState::NONE, "0" },
        { ProposedCombinationState::CONTINUE, "1" },
        { ProposedCombinationState::WIN, "2" },
        { ProposedCombinationState::LOSE, "3" },
};

}

#endif
