#ifndef SRC_IO_CHARCHECKER_H_
#define SRC_IO_CHARCHECKER_H_

namespace IO {

#include <string>

class CharChecker {
public:
    CharChecker(std::string validChars) :
        validChars(validChars)
    {
    }
    virtual ~CharChecker(){
    }

    virtual char getValidChar(char c) const {
        return (validChars.find(c) != std::string::npos ? c : 0);
    }

    void addChars(std::string addon){
        validChars.append(addon);
    }
protected:
    std::string validChars;
};

class CharUpperCaseChecker : public CharChecker{
public:
    CharUpperCaseChecker(std::string validChars) :
        CharChecker(validChars)
    {
        for (auto & c: validChars) {
            c = toupper(c);
        }
    }

    virtual char getValidChar(char c) const override final{
        return (CharChecker::getValidChar(toupper(c)));
    }
};

class CharLowerCaseChecker : public CharChecker{
public:
    CharLowerCaseChecker(std::string validChars) :
        CharChecker(validChars)
    {
        for (auto & c: validChars) {
            c = tolower(c);
        }
    }

    virtual char getValidChar(char c) const override final {
        return (CharChecker::getValidChar(tolower(c)));
    }
};

}

#endif
