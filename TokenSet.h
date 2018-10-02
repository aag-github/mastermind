#ifndef _TOKENSET_H
#define _TOKENSET_H

#include <vector>
#include <time.h>

namespace Mastermind
{

typedef uint8_t TokenId;

class TokenSet {
private:
    static constexpr TokenId emptyToken = 0;
    static constexpr TokenId defaultMaxTokenId = 6;
    static constexpr size_t defaultNumTokens = 4;

    std::vector<TokenId> tokens;

    TokenId maxTokenId;

public:
    TokenSet():
    tokens(defaultNumTokens, emptyToken),
    maxTokenId(defaultMaxTokenId)
    {
    }

    TokenSet(size_t numTokens, size_t maxTokenId):
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

    TokenMatches match(const TokenSet &target) const
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

        return TokenMatches(fullMatches, colorMatches);
    }

    void random()
    {
        for (auto &t : tokens){
            t = (rand()%maxTokenId) + 1;
        }
    }

    void paint() const
    {
        std::string tokenColors("-RGBYOM");
        for (const auto &t : tokens) {
            std::cout << tokenColors[t];
        }
        printf("\n");
    }
};

}
#endif
