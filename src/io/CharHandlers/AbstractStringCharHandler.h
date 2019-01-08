#ifndef SRC_IO_ABSTRACTSTRINGCHARHANDLER_H_
#define SRC_IO_ABSTRACTSTRINGCHARHANDLER_H_

#include "CharHandlerContext.h"

namespace IO {

enum class HandlerResult {
    STOP_PROCESSING,
    CONTINUE_TO_NEXT_HANDLER,
};

class AbstractStringCharHandler {
public:
    AbstractStringCharHandler(){};
    virtual ~AbstractStringCharHandler(){};
    virtual HandlerResult handle(CharHandlerContext *context) = 0;
};

}

#endif
