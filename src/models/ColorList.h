#ifndef SRC_MODELS_COLORLIST_H_
#define SRC_MODELS_COLORLIST_H_

#include <assert.h>
#include <map>
#include <vector>

namespace Mastermind {

class ColorList {
public:
    enum class Color {
        NOCOLOR,
        RED,
        GREEN,
        BLUE,
        YELLOW,
        ORANGE,
        MAGENTA
    };

    static Color getRandom() {
        size_t offset = (rand()%colors.size());
        auto item = colors.cbegin();
        while (offset-- > 0) {
            item++;
        }
        return item->first;
    };

    static char getCode(Color color) {
        assert(color != Color::NOCOLOR);
        return colors[color];
    }

    static Color getColor(char code){
        for(auto &color : colors) {
            if (color.second == code) {
                return color.first;
            }
        }
        return Color::NOCOLOR;
    }

    static std::string getCodes(){
        std::string codes;
        for(auto &color : colors) {
            codes += color.second;
        }
        return codes;
    }

    static std::vector<Color> getColors(){
        std::vector<Color> colorVector;
        for(auto &color : colors) {
            colorVector.push_back(color.first);
        }
        return colorVector;
    }

private :
    static std::map<Color, char> colors;
};

}

#endif
