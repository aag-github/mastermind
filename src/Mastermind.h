#ifndef _MASTERMIND_H
#define _MASTERMIND_H

#include "ArgParser.h"
#include "OperationController.h"
#include "client/ClientLogic.h"
#include "server/ServerLogic.h"
#include "MastermindView.h"

namespace Mastermind
{

class MastermindPlayer {
public:
    virtual ~MastermindPlayer(){};

    virtual void play() = 0;
};

template <class LOGIC, class VIEW, class OPERATION_CONTROLLER> class MastermindTemplate : public MastermindPlayer {
private:
    LOGIC *logic;

    VIEW view;

public:
    MastermindTemplate(LOGIC *logic) :
        logic(logic)
    {
    }

    virtual ~MastermindTemplate()
    {
        delete logic;
    }

    virtual void play() override final {
        OPERATION_CONTROLLER* controller;
        do {
            controller = logic->getController();
            if (controller != nullptr){
                view.interact(controller);
            }
        } while (controller != nullptr);
    }

};

class ClientMastermind : public MastermindTemplate<ClientLogic, ClientMastermindView, ClientOperationController> {
public:
    ClientMastermind(ClientLogic *logic) :
        MastermindTemplate(logic) {

    }
};

class ServerMastermind : public MastermindTemplate<ServerLogic, ServerMastermindView, ServerOperationController> {
public:
    ServerMastermind(ServerLogic *logic) :
        MastermindTemplate(logic) {

    }
};

}

#endif
