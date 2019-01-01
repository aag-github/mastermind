#ifndef SRC_INTREADER_H_
#define SRC_INTREADER_H_

#include "DialogReadString.h"
#include <stdio.h>

namespace IO
{

class DialogReadInteger : public DialogReadString {
public:
    DialogReadInteger(std::string title) :
        DialogReadString(title, &integerCharChecker),
        integerCharChecker("+-0123456789")
    {
    }

    virtual ~DialogReadInteger() {
    }

    int read() {
        std::string intString = DialogReadString::read();
        return atoi(intString.c_str());
    }

    int read(int min, int max) {
        assert(min <= max);
        int value;
        do {
            value = read();
            if (value >= min && value <= max) {
                break;
            } else {
                printf("The value must be between %d and %d\n", min, max);
            }
        } while (true);
        return value;
    }

    virtual bool isCharValid(std::string current, int newChar) {
        return (current.empty() || (newChar != '-' && newChar != '+'));
    }

private:
    CharChecker integerCharChecker;
};

}
#endif
