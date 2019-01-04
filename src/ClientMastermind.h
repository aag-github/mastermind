#ifndef _CLIENTMASTERMIND_H
#define _CLIENTMASTERMIND_H

#include "Mastermind.h"
#include "client/ClientOperationController.h"
#include "client/ClientLogic.h"
#include "client/ClientMastermindView.h"

namespace Mastermind
{

class ClientMastermind : public MastermindTemplate<ClientLogic, ClientMastermindView, ClientOperationController> {
public:
    ClientMastermind(ClientLogic *logic) :
        MastermindTemplate(logic) {
    }
};

}

#endif
