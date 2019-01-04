#ifndef _MASTERMINDBUILDER_H
#define _MASTERMINDBUILDER_H

#include "ArgParser.h"

namespace Mastermind
{

class Mastermind;

class MastermindBuilder {
private:
    static MastermindBuilder *builderInstance;
protected:
    MastermindBuilder();

public:
    ~MastermindBuilder() {
    }

    static MastermindBuilder* instance();

    Mastermind* build(const ArgParser &parser) const;

    static void cleanup() {
        delete builderInstance;
    }
};

}

#endif
