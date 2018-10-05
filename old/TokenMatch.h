#ifndef _HINTSET_H
#define _HINTSET_H

#include <stdint.h>
#include <stdio.h>

namespace Mastermind
{

class TokenMatch {
private:
    uint8_t fullMatches;

    uint8_t colorMatches;

public:
    enum class Result
    {
        MATCH,
        MISMATCH
    };

    TokenMatch() :
        fullMatches(0),
        colorMatches(0)
    {
    }

    TokenMatch(uint8_t fullMatches, uint8_t colorMatches) :
        fullMatches(fullMatches),
        colorMatches(colorMatches)
    {
    }

    bool isFullMatch(uint8_t numMatches) {
        return (fullMatches == numMatches);
    }

    void paint() const
    {
        printf("B: %d - ", int(fullMatches));
        printf("W: %d", int(colorMatches));
    }
};

}

#endif
