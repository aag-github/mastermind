#ifndef SRC_CONTROLLERS_SERVER_SERVERCOMMAND_H_
#define SRC_CONTROLLERS_SERVER_SERVERCOMMAND_H_

#include <assert.h>
#include <vector>
#include <string>
#include <sstream>
#include <map>

namespace Mastermind {

class ServerCommand {
public:
    enum class Command {
        NONE,
        OK,
        GET_STATE,
        SET_STATE,
        GET_SECRET_COMBINATION,
        GET_PROPOSED_COMBINATIONS,
        START,
        SET_PROPOSED_COMBINATION,
        SET_SECRET_COMBINATION,
        CREATE_MEMENTO,
        RESTORE_MEMENTO,
        ADD_UNDO,
        CAN_UNDO,
        CAN_REDO,
        UNDO,
        REDO,
        CLEAR_UNDO_REDO,
    };

    static std::string getCommandString(Command command){
        auto item = commandMap.find(command);
        assert(item != commandMap.end());
        return item->second;
    }

    static Command getCommandId(std::string command){
        for(auto &item : commandMap) {
            if(item.second == command) {
                return item.first;
            }
        }
        assert(false);
        return Command::NONE;
    }

    static std::string buildRequest (Command command, std::string value = "") {
        return ServerCommand::getCommandString(command)
                + CMD_SEPARATOR + value;
    }

    static std::string getBoolString(bool b) {
        return b ? ARG_TRUE : ARG_FALSE;
    }

    static bool getBoolValue(std::string s) {
        return s != ARG_FALSE;
    }

    static std::string concatArgs(std::string s1, std::string s2) {
        if (s1.empty()) {
            return s2;
        } else {
            return s1 + ARG_SEPARATOR + s2;
        }
    }

    static std::vector<std::string> splitArgs(std::string args) {
        return split(args, *ARG_SEPARATOR.c_str());
    }

private:
    static std::map<Command, std::string> commandMap ;

    static std::string CMD_SEPARATOR;
    static std::string ARG_SEPARATOR;
    static std::string ARG_TRUE;
    static std::string ARG_FALSE;

    static std::vector<std::string> split(std::string str, char separator) {
        std::vector<std::string> ret;
        std::string part;
        std::istringstream is(str);
        while (getline(is, part, separator)) {
            ret.push_back(part);
        }
        return ret;
    }

};

}

#endif
