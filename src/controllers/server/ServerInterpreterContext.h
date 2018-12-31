/*
 * ServerInterpreterContext.h
 *
 *  Created on: 31 Dec 2018
 *      Author: osboxes
 */

#ifndef SRC_CONTROLLERS_SERVER_SERVERINTERPRETERCONTEXT_H_
#define SRC_CONTROLLERS_SERVER_SERVERINTERPRETERCONTEXT_H_

#include "Game.h"

namespace Mastermind {

class ServerInterpreterContext {
public:
    ServerInterpreterContext(Game *game) :
        game(game)
    {
    }

    virtual ~ServerInterpreterContext()
    {
    }

    Game getGame() {
        return game;
    }
private:
    Game *game;
};

} /* namespace Mastermind */

#endif /* SRC_CONTROLLERS_SERVER_SERVERINTERPRETERCONTEXT_H_ */
