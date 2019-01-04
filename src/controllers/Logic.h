#ifndef SRC_CONTROLLERS_LOGIC_H_
#define SRC_CONTROLLERS_LOGIC_H_

namespace Mastermind {

class Game;

class ClientOperationController;

template <class OPERATION_CONTROLLER> class Logic {
public:
    Logic(Game* game) : game(game){

    };

    virtual ~Logic() {
    }

    virtual OPERATION_CONTROLLER* getController() = 0;
protected:
    Game* game;
};

}

#endif
