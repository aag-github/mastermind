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
        const bool maxLengthReached = context->getString().size() == context->getMaxLength();
        const bool maxLengthEnabled = context->getMaxLength() > 0;
        if (context->getNewChar() == CR)
		{
            if (maxLengthEnabled && ! maxLengthReached) {
                return  HandlerResult::DISCARD_CHAR;
            } else {
                return  HandlerResult::DONE;
            }
        }
        return HandlerResult::CONTINUE_TO_NEXT_HANDLER;
    }

};

}

#endif
