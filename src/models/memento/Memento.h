#ifndef SRC_MODELS_MEMENTO_MEMENTO_H_
#define SRC_MODELS_MEMENTO_MEMENTO_H_

#include <string>
#include <vector>

namespace Mastermind {

class GameLocal;

class Memento {
public:
    Memento() {
    }

    virtual ~Memento() {
    }

    friend class GameLocal;
    friend class GameFilePersistenceImpl;
    friend class GameProxy;
    friend class RestoreMementoInterpreter;

    std::string toString() {
        std::string ret;
        for (auto value : values) {
            ret += value + "\n";
        }
        return ret;
    }

    const std::vector<std::string>& get() const {
        return values;
    }
private:
    std::vector<std::string> values;

    void add(const std::string &value) {
        if (value != "") {
            values.push_back(value);
        }
    }
};

}

#endif
