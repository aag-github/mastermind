#ifndef SRC_CONTROLLERS_CONTINUEVIEWCONTROLLER_H_
#define SRC_CONTROLLERS_CONTINUEVIEWCONTROLLER_H_

namespace Mastermind {

class ContinueViewController {
public:
    ContinueViewController() {
    }

    virtual ~ContinueViewController() {
    }

    virtual void resume(bool resume) = 0;
};

}

#endif
