#ifndef SRC_CONTROLLERS_STARTVIEWCONTROLLER_H_
#define SRC_CONTROLLERS_STARTVIEWCONTROLLER_H_

namespace Mastermind {

class StartViewController {
public:
    StartViewController() {
    }

    virtual ~StartViewController() {
    }

    virtual void start() = 0;
};

}

#endif
