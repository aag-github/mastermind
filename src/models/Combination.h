#ifndef SRC_COMBINATION_H_
#define SRC_COMBINATION_H_

#include <assert.h>
#include "ColorList.h"

namespace Mastermind {

class Combination {
    using container=std::vector<ColorList::Color>;
    using const_iterator=typename container::const_iterator;
    using iterator=typename container::iterator;

public:
    static constexpr int MAX_COLORS = 4;

    Combination(){
        colors.resize(MAX_COLORS, ColorList::Color::NOCOLOR);
    }

    virtual ~Combination() {
    }


    virtual void clear() {
        for (auto &color : colors) {
            color = ColorList::Color::NOCOLOR;
        }
    }

    const_iterator begin() const {
        return colors.begin();
    }

    const_iterator end() const {
        return colors.end();
    }

    iterator begin() {
        return colors.begin();
    }

    iterator end() {
        return colors.end();
    }

    size_t size() const {
        return colors.size();
    }

    Combination operator=(const std::string &s) {
        assert(s.size() == colors.size());
        for(size_t i = 0; i < std::min(s.size(), colors.size()); i++) {
            colors[i] = ColorList::getColor(s[i]);
        }
        return *this;
    }
private:

protected:
    std::vector<ColorList::Color> colors;
};

}

#endif
