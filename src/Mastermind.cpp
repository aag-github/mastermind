#include "Mastermind.h"
#include "ExecMode.h"
#include "OperationController.h"
#include "standalone/StandaloneLogic.h"
#include "MastermindView.h"

namespace Mastermind {

Mastermind* Mastermind::build(const ArgParser &parser) {
    Mastermind *mastermind = nullptr;
    switch(parser.getExecMode()) {
        case ExecMode::STANDALONE:
            mastermind = new Mastermind(new StandaloneLogic(), new MastermindView());
            break;
        case ExecMode::CLIENT:
            mastermind = nullptr;
            break;
        case ExecMode::SERVER:
            mastermind = nullptr;
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
