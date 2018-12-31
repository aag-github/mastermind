#ifndef SRC_CONTROLLERS_SERVER_SERVERCOMMAND_H_
#define SRC_CONTROLLERS_SERVER_SERVERCOMMAND_H_

#include <assert.h>
#include <string>
#include <map>

namespace Mastermind {

enum class ServerCommand {
    NONE,
    GET_STATE,
    SET_STATE,
};

class ServerCommandMap {
public:
    static std::string getCommandString(ServerCommand command){
        auto item = commandMap.find(command);
        assert(item != commandMap.end());
        return item->second;
    }

    static ServerCommand getCommandId(std::string command){
        for(auto &item : commandMap) {
            if(item.second == command) {
                return item.first;
            }
        }
        assert(false);
        return ServerCommand::NONE;
    }

private:
    static std::map<ServerCommand, std::string> commandMap ;
};

std::map<ServerCommand, std::string> ServerCommandMap::commandMap = {
        {ServerCommand::GET_STATE , "GETSTATE"},
        {ServerCommand::SET_STATE , "SETSTATE"},
};

}

#endif
