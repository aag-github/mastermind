#ifndef SRC_IO_STRINGCHARHANDLERS_MAXLENGTHHANDLER_H_
#define SRC_IO_STRINGCHARHANDLERS_MAXLENGTHHANDLER_H_

#include "../StringCharHandler.h"

namespace IO {

class MaxLengthHandler : public StringCharHandler {
public:
    MaxLengthHandler(AbstractStringCharHandler *successor) : StringCharHandler(successor) {};
    virtual ~MaxLengthHandler(){};

    virtual HandlerResult handleImpl(CharHandlerContext *context) override final {
        bool maxLengthReached = (context->getString().size() == context->getMaxLength() &&
                context->getMaxLength() > 0) ;
        return maxLengthReached ? HandlerResult::STOP_PROCESSING : HandlerResult::CONTINUE_TO_NEXT_HANDLER;
    }

};

}

#endif
