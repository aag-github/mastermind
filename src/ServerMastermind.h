#ifndef _SERVERMASTERMIND_H
#define _SERVERMASTERMIND_H

#include "Mastermind.h"
#include "server/ServerOperationController.h"
#include "server/ServerLogic.h"
#include "server/ServerMastermindView.h"

namespace Mastermind
{

class ServerMastermind : public MastermindTemplate<ServerLogic, ServerMastermindView, ServerOperationController> {
public:
    ServerMastermind(ServerLogic *logic) :
        MastermindTemplate(logic) {
    }
};

}

#endif
