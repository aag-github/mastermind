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
        HandlerResult result = handleImpl(context);
        if ( result == HandlerResult::CONTINUE_TO_NEXT_HANDLER) {
            return successor->handle(context);
        } else {
            return result;
        }
    }

private:
    AbstractStringCharHandler* successor;

    virtual HandlerResult handleImpl(CharHandlerContext *context) = 0;

};



}

#endif
