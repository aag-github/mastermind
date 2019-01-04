#include <assert.h>
#include "MastermindBuilder.h"
#include "ClientMastermind.h"
#include "ServerMastermind.h"
#include "ExecMode.h"
#include "client/ClientLogic.h"
#include "server/ServerLogic.h"
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

MastermindPlayer* MastermindBuilder::build(const ArgParser &parser) const {
    MastermindPlayer *mastermind = nullptr;
    Game* game = nullptr;
    switch(parser.getExecMode()) {
        case ExecMode::STANDALONE:
            game = new GameLocal();
            mastermind = new ClientMastermind(new ClientLogic(game));
            break;
        case ExecMode::CLIENT:
            game = new GameProxy(parser.getIp(), parser.getPort());
            mastermind = new ClientMastermind(new ClientLogic(game));
            break;
        case ExecMode::SERVER:
            game = new GameLocal();
            mastermind = new ServerMastermind(new ServerLogic(game, parser.getPort()));
            break;
        default:
            assert(false);
    }
    return mastermind;
}



}
