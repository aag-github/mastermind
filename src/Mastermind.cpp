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

Mastermind* Mastermind::build(const ArgParser &parser) {
    Mastermind *mastermind = nullptr;
    Game* game = nullptr;
    switch(parser.getExecMode()) {
        case ExecMode::STANDALONE:
            game = new GameLocal();
            mastermind = new Mastermind(new ClientLogic(game), new MastermindView());
            break;
        case ExecMode::CLIENT:
            game = new GameProxy(parser.getIp(), parser.getPort());
            mastermind = new Mastermind(new ClientLogic(game), new MastermindView());
            break;
        case ExecMode::SERVER:
            game = new GameLocal();
            mastermind = new Mastermind(new ServerLogic(game, parser.getPort()), new MastermindView());
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
