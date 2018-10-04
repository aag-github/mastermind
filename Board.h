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

    TokenCode requestTokenCode() const
    {
        const uint8_t tokenCodeSize = attempts[0].size();

        TokenCode tokenCode = attempts[0];
        tokenCode.clear();

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
    Board(size_t numTries, size_t tokenCodeSize, TokenId maxTokenId) :
    target(tokenCodeSize, maxTokenId)
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

    TokenMatches::Result giveItATry(const uint8_t attemptNumber)
    {
        attempts[attemptNumber] = requestTokenCode();

        return attempts[attemptNumber].match(target);
    }

    void paint() const
    {
        printf("\n");
        uint8_t attempt = 1;
        for (const auto &att : attempts){
            printf("% 3d - ", attempt++);
            att.paint(true);
        }
    }

    void paintTarget() const
    {
        target.paint(false);
    }
};

}
#endif
