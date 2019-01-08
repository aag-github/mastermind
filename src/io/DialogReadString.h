#ifndef SRC_STRINGREADER_H_
#define SRC_STRINGREADER_H_

#include <stdio.h>
#include <functional>
#include <map>

#include "CharHandlers/AbstractStringCharHandler.h"
#include "CharHandlers/ConcreteCharHandlers/AddCharHandler.h"
#include "CharHandlers/ConcreteCharHandlers/BackspaceHandler.h"
#include "CharHandlers/ConcreteCharHandlers/CarriageReturnHandler.h"
#include "CharHandlers/ConcreteCharHandlers/MaxLengthHandler.h"
#include "CharReader.h"

namespace IO
{

class DialogReadString {
public:
    DialogReadString(std::string title = "", CharChecker* charChecker = nullptr) {
        this->title = title;
        this->charChecker = charChecker;
        this->charHandler = new BackspaceHandler(
                            new MaxLengthHandler(
                            new CarriageReturnHandler(
                            new AddCharHandler())));
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
        CharHandlerContext context(&c, len, &returnString);
        while (c != '\n') {
            c = IO::CharReader::read(charChecker);

            charHandler->handle(&context);
        };
        printf("\n");
        return returnString;
    }

private:

    std::string title;

    CharChecker* charChecker;

protected:
    IO::AbstractStringCharHandler *charHandler;
};

}
#endif
