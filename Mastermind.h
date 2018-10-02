#ifndef _MASTERMIND_H
#define _MASTERMIND_H

#include <time.h>
#include "Board.h"

namespace Mastermind
{

class MasterMind {
private:
    static constexpr size_t numAttempts = 15;
    static constexpr size_t tokenSetSize = 4;

	Board board;

public:
	MasterMind():
	board(numAttempts, tokenSetSize)
	{
		srand(time(nullptr));
	};

	void play()
	{
		board.start();

		size_t currentAttemptIndex = 0;
		for(; currentAttemptIndex < numAttempts; currentAttemptIndex++) {
			board.paint();
			if (Board::AttemptResult::MATCH == board.giveItATry(currentAttemptIndex)){
				break;
			}
		}

		paintResult(currentAttemptIndex + 1);
	}

	void paintResult(size_t currentAttempt) const
	{
		printf("-----------------------------\n");

		board.paint();

		if (currentAttempt > this->numAttempts){
			printf("\nNumber of attempts exhausted, LOSER!\n");
		} else {
			printf("\nYou have won in %d tries\n", (int(currentAttempt)));
		}

		printf("\nThe target set of tokens was: ");
		board.paintTarget();
		printf("\n");
	}
};

}
#endif
