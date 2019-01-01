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
    ServerInterpreterContext(Game *game, std::string command, std::string value) :
        game(game),
        command(command),
        args(value)
    {
    }

    virtual ~ServerInterpreterContext()
    {
    }

    Game* getGame() {
        return game;
    }

    std::string getCommand() {
        return command;
    }

    std::string getArgs() {
        return args;
    }

    std::string getReply() {
        return reply;
    }

    void setReply(std::string reply) {
        this->reply = reply;
    }
private:
    Game *game;

    std::string command;

    std::string args;

    std::string reply;
};

} /* namespace Mastermind */

#endif /* SRC_CONTROLLERS_SERVER_SERVERINTERPRETERCONTEXT_H_ */
