#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <vector>
#include "Board.h"
#include "getch.h"
#include "TokenCode.h"

#include "TokenMatches.h"

namespace Mastermind
{

class Board {
private:
    TokenCode target;

    std::vector<TokenCode> attempts;

    const uint8_t tokenCodeSize;

    const TokenId maxTokenId;

    TokenCode requestTokenCode() const
    {
        TokenCode tokenCode(tokenCodeSize, maxTokenId);
        std::string tokenColors("RGBYOM");
        printf("\nEnter %d tokens (valid characters 'RGBYOM'):\n", tokenCodeSize);
        for(int i = 0; i < tokenCodeSize; i++) {
            size_t pos;
            do {
                int c = toupper(getch());
                pos = tokenColors.find(c);
                if (pos != std::string::npos) {
                    printf("%c", c);
                    tokenCode.addToken(i, pos+1);
                }
            } while (pos == std::string::npos);
        }
        printf("\n");
        return tokenCode;
    }
public:
    enum class AttemptResult
    {
        MATCH,
        MISMATCH
    };

    Board(size_t numTries, size_t tokenCodeSize, TokenId maxTokenId) :
    target(tokenCodeSize, maxTokenId),
    tokenCodeSize(tokenCodeSize),
    maxTokenId(maxTokenId)
    {
        attempts.resize(numTries, TokenCode(tokenCodeSize, maxTokenId));
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
        attempts[attemptNumber] = requestTokenCode();
        TokenMatches result = attempts[attemptNumber].match(target);

        result.paint();

        if (result.isFullMatch(tokenCodeSize)) {
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
