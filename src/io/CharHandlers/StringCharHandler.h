#ifndef SRC_IO_STRINGCHARHANDLER_H_
#define SRC_IO_STRINGCHARHANDLER_H_

#include "AbstractStringCharHandler.h"
#include "CharHandlerContext.h"

namespace IO {
class StringCharHandler : public AbstractStringCharHandler {
public:
    StringCharHandler(AbstractStringCharHandler *successor) :
        successor(successor)
    {};
    virtual ~StringCharHandler(){};

    virtual HandlerResult handle(CharHandlerContext *context) {
        if (handleImpl(context) == HandlerResult::STOP_PROCESSING) {
            return HandlerResult::STOP_PROCESSING;
        } else {
            return successor->handle(context);
        }
    }

private:
    AbstractStringCharHandler* successor;

    virtual HandlerResult handleImpl(CharHandlerContext *context) = 0;

};



}

#endif
