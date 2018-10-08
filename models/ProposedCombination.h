#ifndef SRC_PROPOSEDCOMBINATION_H_
#define SRC_PROPOSEDCOMBINATION_H_

#include "CharReader.h"
#include "SecretCombination.h"
#include "Result.h"

namespace Mastermind {

class ProposedCombination : public Combination {
public:
    ProposedCombination():Combination() {
    }

    virtual ~ProposedCombination() {
    }

    void calculateResult(const Combination &secretCombination) {
        result.calculateResult(*this, secretCombination);
    }

    bool isRight() {
        return result.isRight();
    }

    void read(){
        printf("\nEnter %lu tokens (valid characters '%s'):\n", colors.size(), ColorList::getCodes().c_str());
        for(unsigned int i = 0; i < colors.size(); i++) {
            ColorList::Color color;
            do {
                IO::CharUpperCaseChecker charChecker(ColorList::getCodes());
                int colorCode = IO::CharReader::Read(&charChecker);

                color = ColorList::getColor(colorCode);
                if (color != ColorList::Color::NOCOLOR) {
                    printf("%c", colorCode);
                    colors[i] = color;
                }
            } while (color == ColorList::Color::NOCOLOR);
        }
        printf("\n");
    }

    virtual void clear(){
        Combination::clear();
        result = Result();
    }

    void print() {
        Combination::print();
        printf(" ");
        result.print();
    }

private:
    Result result;

};

}

#endif
