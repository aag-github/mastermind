#ifndef SRC_VIEWS_GAMEENDVIEW_H_
#define SRC_VIEWS_GAMEENDVIEW_H_

#include "CombinationView.h"

namespace Mastermind {

class GameEndView {
public:
    GameEndView(const Combination *secretCombination, bool winner) :
        secretCombination(secretCombination),
        winner(winner)
    {
    }

    virtual ~GameEndView() {
    }

    void show() {
        if (winner){
            printf("\nYou have won.\n");
        } else {
            printf("\nNumber of attempts exhausted, LOSER!\n");
        }

        printf("The secret combination was: ");
        CombinationView(secretCombination).show();
        printf("\n\n");
    }

private:
    const Combination *secretCombination;
    bool winner;
};

}

#endif
