#ifndef SRC_IO_STRINGCHARHANDLERS_BACKSPACEHANDLER_H_
#define SRC_IO_STRINGCHARHANDLERS_BACKSPACEHANDLER_H_

#include "../StringCharHandler.h"

namespace IO {

class BackspaceHandler : public StringCharHandler {
public:
    BackspaceHandler(AbstractStringCharHandler *successor) : StringCharHandler(successor) {};
    virtual ~BackspaceHandler(){};

    virtual HandlerResult handleImpl(CharHandlerContext *context) override final {
        constexpr char BACKSPACE = '\x7F';

        if (context->getNewChar() == BACKSPACE) {
            if (context->getString().size() > 0) {
                context->getString().pop_back();
                printf("\b \b");
            }
            return HandlerResult::DISCARD_CHAR;
        }
        return HandlerResult::CONTINUE_TO_NEXT_HANDLER;
    }
private:

};

}

#endif
