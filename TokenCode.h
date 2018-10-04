#ifndef _TOKENSET_H
#define _TOKENSET_H

#include <vector>
#include <time.h>
#include "TokenMatches.h"

namespace Mastermind
{

typedef uint8_t TokenId;

class TokenCode {
private:
    static constexpr TokenId emptyToken = 0;
    static constexpr TokenId defaultMaxTokenId = 6;
    static constexpr size_t defaultNumTokens = 4;

    std::vector<TokenId> tokens;
    TokenMatches matches;
    TokenId maxTokenId;

public:
    TokenCode():
    tokens(defaultNumTokens, emptyToken),
    maxTokenId(defaultMaxTokenId)
    {
    }

    TokenCode(size_t numTokens, size_t maxTokenId):
    tokens(numTokens, emptyToken),
    maxTokenId(maxTokenId)
    {
    }

    void clear()
    {
        tokens = std::vector<TokenId>(tokens.size(), emptyToken);
    }

    void addToken(size_t pos, TokenId token)
    {
        tokens[pos] = token;
    }

    TokenMatches::Result match(const TokenCode &target)
    {
        uint8_t fullMatches = 0;
        uint8_t colorMatches = 0;
        std::vector<uint8_t> targetColorCounters;
        std::vector<uint8_t> myColorCounters;

        targetColorCounters.resize(maxTokenId, 0);
        myColorCounters.resize(maxTokenId, 0);

        for (size_t i = 0;
                    i < std::min(tokens.size(), target.tokens.size());  // TODO defensive: replace with assert?
                    i++) {
            const TokenId myToken = tokens[i];
            const TokenId targetToken = target.tokens[i];

            if (myToken == emptyToken || targetToken == emptyToken) {
                continue;
            }

            if (myToken == targetToken){
                fullMatches++;
            } else if (targetToken < maxTokenId && myToken < maxTokenId){  // TODO defensive: replace with assert?
                targetColorCounters[targetToken]++;
                myColorCounters[myToken]++;
            }
        }

        for(size_t i = 0; i < targetColorCounters.size(); i++){
            colorMatches += std::min(targetColorCounters[i], myColorCounters[i]);
        }

        matches = TokenMatches(fullMatches, colorMatches);
        if (matches.isFullMatch(tokens.size())) {
            return TokenMatches::Result::MATCH;
        } else {
            return TokenMatches::Result::MISMATCH;
        }
    }

    void random()
    {
        for (auto &t : tokens){
            t = (rand()%maxTokenId) + 1;
        }
    }

    uint8_t size() const {
        return tokens.size();
    }

    void paint(bool paintMatches) const
    {
        std::string tokenColors("-RGBYOM");
        for (const auto &t : tokens) {
            std::cout << tokenColors[t];
        }

        if (paintMatches) {
            printf("  ");
            matches.paint();
        }

        printf("\n");
    }
};

}
#endif
