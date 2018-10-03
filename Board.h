#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <vector>
#include "getch.h"
#include "Board.h"
#include "TokenMatches.h"
#include "TokenSet.h"

namespace Mastermind
{

class Board {
private:
    TokenSet target;

    std::vector<TokenSet> attempts;

    const uint8_t tokenSetSize;

    const TokenId maxTokenId;

    TokenSet requestTokenSet() const
    {
        TokenSet tokenSet(tokenSetSize, maxTokenId);
        std::string tokenColors("RGBYOM");
        printf("\nEnter %d tokens (valid characters 'RGBYOM'):\n", tokenSetSize);
        for(int i = 0; i < tokenSetSize; i++) {
            size_t pos;
            do {
                int c = toupper(getch());
                pos = tokenColors.find(c);
                if (pos != std::string::npos) {
                    printf("%c", c);
                    tokenSet.addToken(i, pos+1);
                }
            } while (pos == std::string::npos);
        }
        printf("\n");
        return tokenSet;
    }
public:
    enum class AttemptResult
    {
        MATCH,
        MISMATCH
    };

    Board(size_t numTries, size_t tokenSetSize, TokenId maxTokenId) :
    target(tokenSetSize, maxTokenId),
    tokenSetSize(tokenSetSize),
    maxTokenId(maxTokenId)
    {
        attempts.resize(numTries, TokenSet(tokenSetSize, maxTokenId));
    }

    void start()
    {
        target.random();
        for(auto &att : attempts){
            att.clear();
        }
    }

    AttemptResult giveItATry(const uint8_t attemptNumber)
    {
        attempts[attemptNumber] = requestTokenSet();
        TokenMatches result = attempts[attemptNumber].match(target);

        result.paint();

        if (result.isFullMatch(tokenSetSize)) {
            return AttemptResult::MATCH;
        } else {
            return AttemptResult::MISMATCH;
        }
    }

    void paint() const
    {
        printf("\n");
        uint8_t attempt = 1;
        for (const auto &att : attempts){
            printf("% 3d - ", attempt++);
            att.paint();
        }
    }

    void paintTarget() const
    {
        target.paint();
    }
};

}
#endif
