#include "ColorList.h"

namespace Mastermind {

std::map<ColorList::Color, char> ColorList::colors = {
        { ColorList::Color::RED, 'R' },
        { ColorList::Color::GREEN, 'G' },
        { ColorList::Color::BLUE, 'B' },
        { ColorList::Color::YELLOW, 'Y' },
        { ColorList::Color::ORANGE, 'O' },
        { ColorList::Color::MAGENTA, 'M' }
};

}
