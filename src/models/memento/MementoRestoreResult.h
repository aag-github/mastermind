#ifndef SRC_MODELS_MEMENTO_MEMENTORESTORERESULT_H_
#define SRC_MODELS_MEMENTO_MEMENTORESTORERESULT_H_

#include <assert.h>
#include <map>

namespace Mastermind {

enum class MementoRestoreResult {
    OK = 0,
    SECRET_COMBINATION_ERROR,
    PROPOSED_COMBINATION_ERROR,
};

class MementoRestoreResultMap {
public:
    static std::string getMementoRestoreResultString(MementoRestoreResult result){
        auto item = map.find(result);
        assert(item != map.end());
        return item->second;
    }

    static MementoRestoreResult getMementoRestoreResultId(std::string result){
        for(auto &item : map) {
            if(item.second == result) {
                return item.first;
            }
        }
        assert(false);
        return MementoRestoreResult::OK;
    }

private:
    static std::map<MementoRestoreResult, std::string> map ;
};

std::map<MementoRestoreResult, std::string> MementoRestoreResultMap::map = {
        { MementoRestoreResult::OK, "0" },
        { MementoRestoreResult::SECRET_COMBINATION_ERROR, "1" },
        { MementoRestoreResult::PROPOSED_COMBINATION_ERROR, "2" },
};
}

#endif /* SRC_MODELS_MEMENTO_MEMENTORESTORERESULT_H_ */
