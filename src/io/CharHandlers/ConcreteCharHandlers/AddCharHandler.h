
#ifndef SRC_IO_STRINGCHARHANDLERS_ADDCHARHANDLER_H_
#define SRC_IO_STRINGCHARHANDLERS_ADDCHARHANDLER_H_

#include "../StringCharHandlerLeaf.h"

namespace IO {

class AddCharHandler : public StringCharHandlerLeaf {
public:
    AddCharHandler(){};
    virtual ~AddCharHandler(){};

    virtual void handleImpl(CharHandlerContext *context) override final {
        context->getString() += context->getNewChar();
        printf("%c", context->getNewChar());
    }
};

}

#endif
