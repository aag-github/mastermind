#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <vector>
#include "Board.h"
#include "getch.h"

#include "TokenMatches.h"
#include "TokenSet.h"

namespace Mastermind
{

class Board {
private:
    TokenSet target;

    std::vector<TokenSet> attempts;

    const uint8_t tokenSetSize;

    TokenSet requestTokenSet() const
	{
    	TokenSet s(tokenSetSize);
    	std::string tokenColors("RGBYOM");
    	std::string tokenSet;
		printf("\nEnter %d tokens (valid characters 'RGBYOM'):\n", tokenSetSize);
    	while(tokenSet.length() < tokenSetSize) {
    		int c = toupper(getch());
    		if (tokenColors.find(c) != std::string::npos) {
    			printf("%c", c);
    			tokenSet += c;
    		}
    	}
		printf("\n");
    	s.set(tokenSet);
    	return s;
	}
public:
    enum class AttemptResult
	{
    	MATCH,
		MISMATCH
    };

	Board(size_t numTries, size_t tokenSetSize) :
	target(tokenSetSize),
	tokenSetSize(tokenSetSize)
	{
		attempts.resize(numTries, TokenSet(tokenSetSize));
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
		TokenMatches result;

		attempts[attemptNumber] = requestTokenSet();
		result = attempts[attemptNumber].match(target);

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
