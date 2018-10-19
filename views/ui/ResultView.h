#ifndef SRC_VIEWS_RESULTVIEW_H_
#define SRC_VIEWS_RESULTVIEW_H_

#include "Result.h"

namespace Mastermind {

class ResultView {
public:
    ResultView(const Result *result) :
        result(result)
    {
    }

    virtual ~ResultView(){
    };

    void show() const {
        printf("D: %d - I: %d", result->getDead(), result->getInjured());
    }
private:
    const Result *result;
};

}

#endif
