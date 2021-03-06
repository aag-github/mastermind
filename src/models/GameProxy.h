#ifndef SRC_MODELS_GAMEPROXY_H_
#define SRC_MODELS_GAMEPROXY_H_

#include <sstream>
#include "Game.h"
#include <memento/MementoManager.h>
#include "State.h"
#include "server/ServerCommand.h"
#include "SecretCombination.h"
#include "ProposedCombinationList.h"
#include "ProposedCombinationState.h"
#include "TCPClient.h"

namespace Mastermind {

class GameProxy : public Game {
public:
    static constexpr int MAX_PROPOSED_COMBINATION = 10;

    GameProxy(std::string ip, int port) :
        Game(),
        ip(ip),
        port(port)
    {
    }

    virtual ~GameProxy(){
    }

    State getState() const {
        std::string reply = send(ServerCommand::buildRequest(ServerCommand::Command::GET_STATE));
        return StateMap::getState(atoi(reply.c_str()));
    }

    void setState(State state) {
        send("SETSTATE:" + std::to_string(size_t(state)));
    }

    const SecretCombination& getSecretCombination() const {
        static SecretCombination secretCombination;
        std::string secret = send(ServerCommand::buildRequest(ServerCommand::Command::GET_SECRET_COMBINATION));
        secretCombination = secret;
        return secretCombination;
    }

    const ProposedCombinationList& getProposedCombinations() const {
        std::string reply = send(ServerCommand::buildRequest(ServerCommand::Command::GET_PROPOSED_COMBINATIONS));

        static ProposedCombinationList proposedCombinations;
        proposedCombinations.clear();
        proposedCombinations.resize(MAX_PROPOSED_COMBINATION);

        auto values = ServerCommand::splitArgs(reply);
        int count = 0;
        int current = 0;
        for (auto value = values.begin(); value != values.end(); value++) {
            if (value == values.begin()){
                count = atoi(value->c_str());
            } else if (current < count) {
                Combination combination;
                combination = *value;
                value++;
                int dead = atoi(value->c_str());
                value++;
                int injured = atoi(value->c_str());
                Result result(dead,injured);
                proposedCombinations[current++] = ProposedCombination(combination, result);
            }
        }
        return proposedCombinations;
    }

    void start(bool recordUndoEvent = true) {
        send(ServerCommand::buildRequest(ServerCommand::Command::START,
                                         ServerCommand::getBoolString(recordUndoEvent)));
    }

    ProposedCombinationState setProposedCombination(const Combination& proposedCombination, bool recordUndoEvent = true) {
        std::string args = ServerCommand::concatArgs(proposedCombination.getString(),
                                                     ServerCommand::getBoolString(recordUndoEvent));
        std::string reply = send(ServerCommand::buildRequest(ServerCommand::Command::SET_PROPOSED_COMBINATION,
                                 args));
        return ProposedCombinationStateMap::getStateId(reply);
    }

    void setSecretCombination(const SecretCombination& secretCombination, bool recordUndoEvent = true) {
        std::string args = ServerCommand::concatArgs(secretCombination.getString(),
                                                     ServerCommand::getBoolString(recordUndoEvent));
        send(ServerCommand::buildRequest(ServerCommand::Command::SET_SECRET_COMBINATION,
                args));
    }

    virtual std::shared_ptr<Memento> createMemento() const override final {
        std::string reply = send(ServerCommand::buildRequest(ServerCommand::Command::CREATE_MEMENTO));
        auto values = ServerCommand::splitArgs(reply);

        std::shared_ptr<Memento> memento = std::make_shared<Memento>();
        for (auto value = values.begin(); value != values.end(); value++) {
            if (value != values.begin()){
                memento->add(*value);
            }
        }
        return memento;
    }

    virtual MementoRestoreResult restoreMemento(std::shared_ptr<Memento> memento, bool recordUndoEvent) override final {

        std::string args = std::to_string(memento->get().size());
        for(auto str : memento->get()) {
            args = ServerCommand::concatArgs(args, str);
        }
        args = ServerCommand::concatArgs(args, ServerCommand::getBoolString(recordUndoEvent));

        std::string reply = send(ServerCommand::buildRequest(ServerCommand::Command::RESTORE_MEMENTO,
                                 args));

        return MementoRestoreResultMap::getMementoRestoreResultId(reply);
    }

    virtual void AddUndo() override final {
        send(ServerCommand::buildRequest(ServerCommand::Command::ADD_UNDO));
    }

    virtual bool canUndo() override final {
        std::string reply = send(ServerCommand::buildRequest(ServerCommand::Command::CAN_UNDO));
        return ServerCommand::getBoolValue(reply);
    }

    virtual bool canRedo() override final {
        std::string reply = send(ServerCommand::buildRequest(ServerCommand::Command::CAN_REDO));
        return ServerCommand::getBoolValue(reply);
    }

    virtual bool Undo() override final {
        std::string reply = send(ServerCommand::buildRequest(ServerCommand::Command::UNDO));
        return ServerCommand::getBoolValue(reply);
    }

    virtual bool Redo() override final {
        std::string reply = send(ServerCommand::buildRequest(ServerCommand::Command::REDO));
        return ServerCommand::getBoolValue(reply);
    }

    virtual void clearUndoRedo() override final {
        send(ServerCommand::buildRequest(ServerCommand::Command::CLEAR_UNDO_REDO));
    }
private:
    std::string send(std::string message) const {
        TCPClient tcpclient;
        tcpclient.setup(ip, port);
        tcpclient.Send(message);
        std::string rec = tcpclient.receive();
        return rec;
    }

    std::string ip;

    int port;
};

}

#endif
