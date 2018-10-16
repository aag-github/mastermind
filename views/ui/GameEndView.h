#ifndef SRC_VIEWS_GAMEENDVIEW_H_
#define SRC_VIEWS_GAMEENDVIEW_H_

#include "CombinationView.h"

namespace Mastermind {

class GameEndView {
public:
    GameEndView(Combination *secretCombination, bool winner) :
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
    Combination *secretCombination;
    bool winner;
};

} /* namespace Mastermind */

#endif
