#ifndef SRC_VIEWS_COMBINATIONVIEW_H_
#define SRC_VIEWS_COMBINATIONVIEW_H_

#include <sstream>
#include "Combination.h"
#include "DialogReadString.h"

namespace Mastermind {

class CombinationView {
public:
    CombinationView(const Combination *combination) :
        combination(combination)
    {
    }

    virtual ~CombinationView(){
    };

    virtual void showColor(const ColorList::Color &color) const {
        if (color == ColorList::Color::NOCOLOR) {
            printf("- ");
        } else {
            printf("%c ", ColorList::getCode(color));
        }
    }

    void show() const {
        for (auto &color : *combination){
            showColor(color);
        }
    }

    static Combination read() {
        Combination newCombination;
        std::stringstream title;

        title << "Enter " << newCombination.size() << " colors (valid characters '" << ColorList::getCodes() << "'):\n";

        IO::CharUpperCaseChecker charChecker(ColorList::getCodes());

        IO::DialogReadString reader(title.str(), &charChecker);

        newCombination = reader.read(newCombination.size());

        return newCombination;
    }
private:
    const Combination *combination;
};

}

#endif
