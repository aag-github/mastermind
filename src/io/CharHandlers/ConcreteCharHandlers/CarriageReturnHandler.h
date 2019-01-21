#ifndef SRC_IO_STRINGCHARHANDLERS_CARRIAGERETRUNHANDLER_H_
#define SRC_IO_STRINGCHARHANDLERS_CARRIAGERETRUNHANDLER_H_

#include "../StringCharHandler.h"

namespace IO {

class CarriageReturnHandler: public StringCharHandler {
public:
    CarriageReturnHandler(AbstractStringCharHandler *successor) : StringCharHandler(successor) {};
    virtual ~CarriageReturnHandler(){};

    virtual HandlerResult handleImpl(CharHandlerContext *context) override final {
        constexpr int CR = '\n';
        const bool maxLengthReached = context->getString().size() != context->getMaxLength();
        if (context->getNewChar() == CR
            && (maxLengthReached || context->getMaxLength() == 0)) {
            return HandlerResult::STOP_PROCESSING;
        }
        return HandlerResult::CONTINUE_TO_NEXT_HANDLER;
    }

};

}

#endif
