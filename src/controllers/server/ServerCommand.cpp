#include "ServerCommand.h"

namespace Mastermind {

std::map<ServerCommand::Command, std::string> ServerCommand::commandMap = {
        {ServerCommand::Command::NONE , ""},
        {ServerCommand::Command::OK , "OK"},
        {ServerCommand::Command::GET_STATE , "GETSTATE"},
        {ServerCommand::Command::SET_STATE , "SETSTATE"},
        {ServerCommand::Command::GET_SECRET_COMBINATION,"GETSECRET"},
        {ServerCommand::Command::GET_PROPOSED_COMBINATIONS,"GETPROPOSED"},
        {ServerCommand::Command::START,"START"},
        {ServerCommand::Command::SET_PROPOSED_COMBINATION,"SETPROPOSED"},
        {ServerCommand::Command::SET_SECRET_COMBINATION,"SETSECRET"},
        {ServerCommand::Command::CREATE_MEMENTO,"CREATEMEMENTO"},
        {ServerCommand::Command::RESTORE_MEMENTO,"RESTOREMEMENTO"},
        {ServerCommand::Command::ADD_UNDO,"ADDUNDO"},
        {ServerCommand::Command::CAN_UNDO,"CANUNDO"},
        {ServerCommand::Command::CAN_REDO,"CANREDO"},
        {ServerCommand::Command::UNDO,"UNDO"},
        {ServerCommand::Command::REDO,"REDO"},
        {ServerCommand::Command::CLEAR_UNDO_REDO,"CLEARUNDOREDO"},

};

std::string ServerCommand::CMD_SEPARATOR = ":";
std::string ServerCommand::ARG_SEPARATOR = "\n";
std::string ServerCommand::ARG_TRUE = "1";
std::string ServerCommand::ARG_FALSE = "0";

}
