#ifndef SRC_IO_ABSTRACTSTRINGCHARHANDLER_H_
#define SRC_IO_ABSTRACTSTRINGCHARHANDLER_H_

#include "CharHandlerContext.h"

namespace IO {

enum class HandlerResult {
    DISCARD_CHAR,
    CONTINUE_TO_NEXT_HANDLER,
    DONE
};

class AbstractStringCharHandler {
public:
    AbstractStringCharHandler(){};
    virtual ~AbstractStringCharHandler(){};
    virtual HandlerResult handle(CharHandlerContext *context) = 0;
};

}

#endif
