#ifndef SRC_PROPOSEDCOMBINATION_H_
#define SRC_PROPOSEDCOMBINATION_H_

#include "../io/getch.h"
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
                int c = toupper(IO::getch());
                color = ColorList::getColor(c);
                if (color != ColorList::Color::NOCOLOR) {
                    printf("%c", c);
                    colors[i] = color;
                }
            } while (color == ColorList::Color::NOCOLOR);
        }
        printf("\n");
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
