#ifndef SRC_COMBINATION_H_
#define SRC_COMBINATION_H_

#include "ColorList.h"

namespace Mastermind {

class Combination {
    using container=std::vector<ColorList::Color>;
    using const_iterator=typename container::const_iterator;

public:
    static constexpr int MAX_COLORS = 4;

    Combination(){
        colors.resize(MAX_COLORS, ColorList::Color::NOCOLOR);
    }

    virtual ~Combination() {
    }

    virtual void print(){
        for (auto &color : colors){
            if (color != ColorList::Color::NOCOLOR) {
                printf("%c", ColorList::getCode(color));
            } else {
                printf("-");
            }
        }
    }

    const_iterator begin() const {
        return colors.begin();
    }

    const_iterator end() const {
        return colors.end();
    }


    virtual void clear() {
        for (auto &color : colors) {
            color = ColorList::Color::NOCOLOR;
        }
    }

private:

protected:
    std::vector<ColorList::Color> colors;
};

}

#endif
