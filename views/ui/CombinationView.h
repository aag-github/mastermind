#ifndef SRC_VIEWS_COMBINATIONVIEW_H_
#define SRC_VIEWS_COMBINATIONVIEW_H_

#include "Combination.h"

namespace Mastermind {

class CombinationView {
public:
    CombinationView(const Combination *combination) :
        combination(combination)
    {
    }

    virtual ~CombinationView(){
    };

    void show(bool hide = false) const {
        for (auto &color : *combination){
            if (hide) {
                printf("X ");
            }
            else if (color != ColorList::Color::NOCOLOR) {
                printf("%c ", ColorList::getCode(color));
            } else {
                printf("- ");
            }
        }
    }

    static Combination read() {
        Combination newCombination;
        printf("Enter %lu tokens (valid characters '%s'):\n", newCombination.size(), ColorList::getCodes().c_str());
        IO::CharUpperCaseChecker charChecker(ColorList::getCodes());
        for(auto &currentColor : newCombination) {
            int colorCode = IO::CharReader::read(&charChecker);
            printf("%c", colorCode);
            currentColor = ColorList::getColor(colorCode);
        }
        printf("\n");
        return newCombination;
    }
private:
    const Combination *combination;
};

}

#endif
