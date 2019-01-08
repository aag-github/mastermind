#ifndef SRC_IO_STRINGCHARHANDLERLEAF_H_
#define SRC_IO_STRINGCHARHANDLERLEAF_H_

#include "AbstractStringCharHandler.h"
#include "CharHandlerContext.h"

namespace IO {

class StringCharHandlerLeaf : public AbstractStringCharHandler{
public:
    StringCharHandlerLeaf()
    {};
    virtual ~StringCharHandlerLeaf(){};

    virtual HandlerResult handle(CharHandlerContext *context) {
        handleImpl(context);
        return HandlerResult::STOP_PROCESSING;
    }

    virtual void handleImpl(CharHandlerContext *context) = 0;
private:
};

}

#endif
