#ifndef SRC_MODELS_GAMEPROXY_H_
#define SRC_MODELS_GAMEPROXY_H_

#include <memento/MementoManager.h>
#include "State.h"
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
        state(State::INITIAL),
        currentProposedCombination(0),
        undoRedoManager(this)
    {
        proposedCombinations.resize(MAX_PROPOSED_COMBINATION);
        tcpclient.setup(ip,port);
    }

    virtual ~GameProxy(){
    }

    void send() {
        while(1)
        {
            srand(time(NULL));
            tcpclient.Send(std::to_string(rand()%25000));
            std::string rec = tcpclient.receive();
            if( rec != "" )
            {
                std::cout << "Server Response:" << rec << std::endl;
            }
            sleep(1);
        }
    }

    State getState() const {
        //TODO: implement call to proxy
        return state;
    }

    void setState(State state) {
        //TODO: implement call to proxy
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

    SecretCombination secretCombination;

    ProposedCombinationList proposedCombinations;

    State state;

    size_t currentProposedCombination;

    MementoManager undoRedoManager;

    TCPClient tcpclient;
};

}

#endif
