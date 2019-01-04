#include "MementoRestoreResult.h"

namespace Mastermind {

std::map<MementoRestoreResult, std::string> MementoRestoreResultMap::map = {
        { MementoRestoreResult::OK, "0" },
        { MementoRestoreResult::SECRET_COMBINATION_ERROR, "1" },
        { MementoRestoreResult::PROPOSED_COMBINATION_ERROR, "2" },
};

}

