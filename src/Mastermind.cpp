#include <assert.h>
#include "Mastermind.h"
#include "ExecMode.h"
#include "OperationController.h"
#include "client/ClientLogic.h"
#include "server/ServerLogic.h"
#include "MastermindView.h"
#include "Game.h"
#include "GameProxy.h"
#include "GameLocal.h"

namespace Mastermind {

Mastermind::~Mastermind()
{
    delete logic;
    delete view;
}

void Mastermind::play()
{
    OperationController* controller;
    do {
        controller = logic->getController();
        if (controller != nullptr){
            view->interact(controller);
        }
    } while (controller != nullptr);
}


}
