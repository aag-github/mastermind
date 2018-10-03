#ifndef _HINTSET_H
#define _HINTSET_H

#include <stdint.h>
#include <stdio.h>

namespace Mastermind
{

class TokenMatches {
private:
    uint8_t fullMatches;

    uint8_t colorMatches;

public:
    TokenMatches() :
    fullMatches(0),
    colorMatches(0)
    {
    }

    TokenMatches(uint8_t fullMatches, uint8_t colorMatches) :
    fullMatches(fullMatches),
    colorMatches(colorMatches)
    {
    }

    bool isFullMatch(uint8_t numMatches) {
        return (fullMatches == numMatches);
    }

    void paint() const
    {
        printf("-----------------------------\n");
        printf("Full matches:  %d - ", int(fullMatches));
        printf("Color matches: %d\n", int(colorMatches));
    }
};

}

#endif
