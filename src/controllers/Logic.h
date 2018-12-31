#ifndef SRC_CONTROLLERS_LOGIC_H_
#define SRC_CONTROLLERS_LOGIC_H_

namespace Mastermind {

class OperationController;

class Logic {
public:
    Logic()
    {
    }
    virtual ~Logic() {
    }

    virtual OperationController* getController() = 0;
};

}

#endif
