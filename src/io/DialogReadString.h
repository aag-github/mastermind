#ifndef SRC_STRINGREADER_H_
#define SRC_STRINGREADER_H_

#include "CharReader.h"
#include <stdio.h>
#include <functional>
#include <map>


namespace IO
{

class DialogReadString {
public:
    DialogReadString(std::string title = "", CharChecker* charChecker = nullptr) {
        this->title = title;
        this->charChecker = charChecker;
    }

    virtual ~DialogReadString() {};

    std::string read() {
        printf("%s", title.c_str());

        constexpr char BACKSPACE = '\x7F';
        if (charChecker) {
            charChecker->addChars("\n" + std::string(&BACKSPACE));
        }
        std::string returnString;
        int c = 0;
        while ((c = IO::CharReader::read(charChecker)) != '\n') {
            if (!isCharValid(returnString, c)) {
                continue;
            }

            if (c == BACKSPACE) {
                if (returnString.size() > 0) {
                    returnString.pop_back();
                    printf("\b \b");
                }
            } else {
                returnString += char(c);
                printf("%c", c);
            }
        };
        printf("\n");
        return returnString;
    }

private:
    virtual bool isCharValid(std::string current, int newChar) {
        return true;
    }

    std::string title;

    CharChecker* charChecker;
};

}
#endif
