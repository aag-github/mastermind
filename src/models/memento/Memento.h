#ifndef SRC_MODELS_MEMENTO_MEMENTO_H_
#define SRC_MODELS_MEMENTO_MEMENTO_H_

#include <string>
#include <vector>

namespace Mastermind {

class Game;

class Memento {
public:
    Memento() {
    }

    virtual ~Memento() {
    }

    friend class Game;

    std::string toString() {
        std::string ret;
        for (auto value : values) {
            ret += value + "\n";
        }
        return ret;
    }
private:
    std::vector<std::string> values;

    const std::vector<std::string>& get() const {
        return values;
    }

    void add(const std::string &value) {
        values.push_back(value);
    }
};

}

#endif
