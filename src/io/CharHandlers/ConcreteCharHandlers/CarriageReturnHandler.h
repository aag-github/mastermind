#ifndef SRC_IO_STRINGCHARHANDLERS_CARRIAGERETRUNHANDLER_H_
#define SRC_IO_STRINGCHARHANDLERS_CARRIAGERETRUNHANDLER_H_

#include "../StringCharHandler.h"

namespace IO {

class CarriageReturnHandler: public StringCharHandler {
public:
    CarriageReturnHandler(AbstractStringCharHandler *successor) : StringCharHandler(successor) {};
    virtual ~CarriageReturnHandler(){};

    virtual HandlerResult handleImpl(CharHandlerContext *context) override final {
        constexpr char CR = '\n';

        if (context->getNewChar() == CR
            && context->getString().size() != context->getMaxLength()
            && context->getMaxLength() > 0) {
            context->getNewChar() = 0;
            return HandlerResult::STOP_PROCESSING;
        }
        return HandlerResult::CONTINUE_TO_NEXT_HANDLER;
    }

};

}

#endif
