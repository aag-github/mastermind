#ifndef SRC_CONTROLLERS_LOGIC_H_
#define SRC_CONTROLLERS_LOGIC_H_

namespace Mastermind {

class Game;

class OperationController;

class Logic {
public:
    Logic(Game* game) : game(game)
    {
    }
    virtual ~Logic() {
    }

    virtual OperationController* getController() = 0;
protected:
    Game* game;
};

}

#endif
