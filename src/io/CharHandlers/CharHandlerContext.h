#ifndef SRC_IO_CHARHANDLERS_CHARHANDLERCONTEXT_H_
#define SRC_IO_CHARHANDLERS_CHARHANDLERCONTEXT_H_

#include <string>

namespace IO {

class CharHandlerContext {
public:
    CharHandlerContext(int *newChar, size_t maxLength, std::string *string) :
        newChar(newChar),
        maxLength(maxLength),
        string(string)
    {};
    virtual ~CharHandlerContext(){};

    std::string& getString() {
        return *string;
    }

    void setString(std::string newString) {
        *string = newString;
    }

    size_t getMaxLength() {
        return maxLength;
    }

    int& getNewChar() {
        return *newChar;
    }

    void setNewChar(int newChar) {
        *this->newChar = newChar;
    }

private:
    int *newChar;
    size_t maxLength;
    std::string *string;
};

}

#endif
