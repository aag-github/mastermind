#include <assert.h>
#include "MastermindBuilder.h"
#include "Mastermind.h"
#include "ExecMode.h"
#include "client/ClientLogic.h"
#include "server/ServerLogic.h"
#include "MastermindView.h"
#include "Game.h"
#include "GameProxy.h"
#include "GameLocal.h"

namespace Mastermind {

MastermindBuilder* MastermindBuilder::builderInstance(nullptr);

MastermindBuilder* MastermindBuilder::instance() {
    if (builderInstance == nullptr) {
        builderInstance = new MastermindBuilder();
    }
    return builderInstance;
}

MastermindBuilder::MastermindBuilder() {
}

Mastermind* MastermindBuilder::build(const ArgParser &parser) const {
    Mastermind *mastermind = nullptr;
    Game* game = nullptr;
    switch(parser.getExecMode()) {
        case ExecMode::STANDALONE:
            game = new GameLocal();
            mastermind = new Mastermind(new ClientLogic(game));
            break;
        case ExecMode::CLIENT:
            game = new GameProxy(parser.getIp(), parser.getPort());
            mastermind = new Mastermind(new ClientLogic(game));
            break;
        case ExecMode::SERVER:
            game = new GameLocal();
            mastermind = new Mastermind(new ServerLogic(game, parser.getPort()));
            break;
        default:
            assert(false);
    }
    return mastermind;
}



}
