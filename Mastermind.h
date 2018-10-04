#ifndef _MASTERMIND_H
#define _MASTERMIND_H

#include <time.h>
#include "Board.h"

namespace Mastermind
{

class Mastermind {
private:
    static constexpr size_t numAttempts = 15;
    static constexpr size_t tokenCodeSize = 4;
    static constexpr size_t tokenTypes = 6;

    Board board;

public:
    Mastermind():
    board(numAttempts, tokenCodeSize, tokenTypes)
    {
        srand(time(nullptr));
    };

    void play()
    {
        board.start();

        size_t currentAttemptIndex = 0;
        for(; currentAttemptIndex < numAttempts; currentAttemptIndex++) {
            board.paint();
            //std::cout << "Target";
            //board.paintTarget();
            if (TokenMatches::Result::MATCH == board.giveItATry(currentAttemptIndex)){
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