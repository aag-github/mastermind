#ifndef SRC_IO_STRINGCHARHANDLERS_NEWCHARVALIDHANDLER_H_
#define SRC_IO_STRINGCHARHANDLERS_NEWCHARVALIDHANDLER_H_

#include "../StringCharHandler.h"

namespace IO {

class IntegerSignHandler: public StringCharHandler {
public:
    IntegerSignHandler(AbstractStringCharHandler *successor) : StringCharHandler(successor) {};
    virtual ~IntegerSignHandler(){};

    virtual HandlerResult handleImpl(CharHandlerContext *context) override final {
        bool validChar = (context->getString().empty()
                || (context->getNewChar() != '-' && context->getNewChar() != '+'));

        return validChar ? HandlerResult::CONTINUE_TO_NEXT_HANDLER : HandlerResult::STOP_PROCESSING;
    }

};

}

#endif
