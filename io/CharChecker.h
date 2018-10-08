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

    virtual bool isValidChar(char c){
        return (validChars.find(c) != std::string::npos);
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

    virtual bool isValidChar(char c) override final{
        return (CharChecker::isValidChar(toupper(c)));
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

    virtual bool isValidChar(char c) override final {
        return (CharChecker::isValidChar(tolower(c)));
    }
};

}

#endif
