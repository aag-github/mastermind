#ifndef SRC_MODELS_GAMEPROXY_H_
#define SRC_MODELS_GAMEPROXY_H_

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
        currentProposedCombination(0),
        undoRedoManager(this),
        ip(ip),
        port(port)
    {
        proposedCombinations.resize(MAX_PROPOSED_COMBINATION);
    }

    virtual ~GameProxy(){
    }

    State getState() const {
        std::string reply = send(buildRequest(ServerCommand::GET_STATE, ""));
        return StateMap::getState(atoi(reply.c_str()));
    }

    void setState(State state) {
        send("SETSTATE:" + std::to_string(size_t(state)));
    }

    const SecretCombination& getSecretCombination() const {
        //TODO: implement call to proxy
        return secretCombination;
    }

    const ProposedCombinationList& getProposedCombinations() const {
        //TODO: implement call to proxy
        return proposedCombinations;
    }

    void start(bool recordUndoEvent = true) {
        //TODO: implement call to proxy
    }

    ProposedCombinationState setProposedCombination(const Combination& proposedCombination, bool recordUndoEvent = true) {
        return ProposedCombinationState::CONTINUE;
        //TODO: implement call to proxy
    }

    void setSecretCombination(const SecretCombination& secretCombination, bool recordUndoEvent = true) {
        //TODO: implement call to proxy
    }

    virtual std::shared_ptr<Memento> createMemento() const override final {
        //TODO: implement call to proxy
        std::shared_ptr<Memento> memento = std::make_shared<Memento>();
        return memento;
    }

    virtual MementoRestoreResult restoreMemento(std::shared_ptr<Memento> snapshot, bool recordUndoEvent) override final {
        //TODO: implement call to proxy
        MementoRestoreResult ret = MementoRestoreResult::OK;
        return ret;
    }

    virtual void AddUndo() override final {
        //TODO: implement call to proxy
    }

    virtual bool canUndo() override final {
        //TODO: implement call to proxy
        return false;
    }

    virtual bool canRedo() override final {
        //TODO: implement call to proxy
        return false;
    }

    virtual bool Undo() override final {
        //TODO: implement call to proxy
        return false;
    }

    virtual bool Redo() override final {
        //TODO: implement call to proxy
        return false;
    }

    virtual void clearUndoRedo() override final {
        //TODO: implement call to proxy
    }
private:
    std::string send(std::string message) const {
        TCPClient tcpclient;
        tcpclient.setup(ip, port);
        tcpclient.Send(message);
        std::string rec = tcpclient.receive();
        if( rec != "" )
        {
            std::cout << "Server Response:" << rec << std::endl;
        }
        return rec;
    }

    std::string buildRequest (ServerCommand command, std::string value) const {
        return ServerCommandMap::getCommandString(ServerCommand::GET_STATE)
                + ":" + value;
    }

    SecretCombination secretCombination;

    ProposedCombinationList proposedCombinations;

    size_t currentProposedCombination;

    MementoManager undoRedoManager;

    std::string ip;

    int port;
};

}

#endif
