#include "Mastermind.h"
#include "ExecMode.h"
#include "OperationController.h"
#include "standalone/StandaloneLogic.h"
#include "client/ClientLogic.h"
#include "server/ServerLogic.h"
#include "MastermindView.h"

namespace Mastermind {

Mastermind* Mastermind::build(const ArgParser &parser) {
    Mastermind *mastermind = nullptr;
    switch(parser.getExecMode()) {
        case ExecMode::STANDALONE:
            mastermind = new Mastermind(new StandaloneLogic(), new MastermindView());
            break;
        case ExecMode::CLIENT:
            mastermind = new Mastermind(new ClientLogic(parser.getIp(), parser.getPort()), new MastermindView());
            break;
        case ExecMode::SERVER:
            mastermind = new Mastermind(new ServerLogic(parser.getPort()), new MastermindView());
            break;
    }
    return mastermind;
}

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
