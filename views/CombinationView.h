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

    void show() const {
        for (auto &color : *combination){
            if (color != ColorList::Color::NOCOLOR) {
                printf("%c", ColorList::getCode(color));
            } else {
                printf("-");
            }
        }
    }

    static Combination read() {
        Combination newCombination;
        printf("Enter %lu tokens (valid characters '%s'):\n", newCombination.size(), ColorList::getCodes().c_str());
        int i = 0;
        for(auto &currentColor : newCombination) {
            ColorList::Color color;
            do {
                IO::CharUpperCaseChecker charChecker(ColorList::getCodes());
                int colorCode = IO::CharReader::Read(&charChecker);

                color = ColorList::getColor(colorCode);
                if (color != ColorList::Color::NOCOLOR) {
                    printf("%c", colorCode);
                    currentColor = color;
                }
            } while (color == ColorList::Color::NOCOLOR);
            i++;
        }
        printf("\n");
        return newCombination;
    }
private:
    const Combination *combination;
};

}

#endif
