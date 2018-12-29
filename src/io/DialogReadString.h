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

    std::string read(unsigned len = 0) {
        printf("%s", title.c_str());

        constexpr char BACKSPACE = '\x7F';
        if (charChecker) {
            charChecker->addChars("\n" + std::string(&BACKSPACE));
        }
        std::string returnString;
        int c = 0;
        unsigned count = len;
        while (c != '\n') {
            c = IO::CharReader::read(charChecker);

            if (!isCharValid(returnString, c)) {
                continue;
            }

            if (c == BACKSPACE) {
                if (returnString.size() > 0) {
                    returnString.pop_back();
                    printf("\b \b");
                    count++;
                }
                continue;
            }

            if (count == 0 && len > 0) {
                continue;
            }

            if (c == '\n') {
                if (count > 0 && len > 0) {
                    c = 0;
                    continue;
                }
            } else {
                returnString += char(c);
                printf("%c", c);
                count--;
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
