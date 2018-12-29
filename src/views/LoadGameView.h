#ifndef SRC_VIEWS_LOADGAMEVIEW_H_
#define SRC_VIEWS_LOADGAMEVIEW_H_

#include "LoadGameController.h"
#include "ViewConst.h"

namespace Mastermind {

class LoadGameView {
public:
    LoadGameView(){
    };

    virtual ~LoadGameView(){
    };

    void interact(LoadGameController* controller){
        assert(controller != nullptr);

        std::cout << "\n";

        auto availableGames = controller->getAvailableGames();
        if (availableGames.size() == 0) {
            controller->noGamesAvailable();
            std::cout << "** No games available **\n";
            return;
        }
        std::cout << "Available games:\n" << SECTION_BREAK << "\n";
        for(auto name : availableGames) {
            std::cout << name << "\n";
        }
        std::cout << SECTION_BREAK << "\n";

        std::string name = IO::DialogReadString("\nGame name to load: ").read();

        if (0 != controller->load(name)) {
            std::cout << "\n** Error loading file '" << name << "' **\n";
        }
    }
};

}
#endif
