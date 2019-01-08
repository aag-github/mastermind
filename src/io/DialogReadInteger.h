#ifndef SRC_INTREADER_H_
#define SRC_INTREADER_H_

#include "CharHandlers/ConcreteCharHandlers/IntegerSignHandler.h"
#include "DialogReadString.h"

namespace IO
{

class DialogReadInteger : public DialogReadString {
public:
    DialogReadInteger(std::string title = "") :
        DialogReadString(title, &integerCharChecker),
        integerCharChecker("+-0123456789")
    {
        charHandler = new IntegerSignHandler(charHandler);
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

private:
    CharChecker integerCharChecker;
};

}
#endif
