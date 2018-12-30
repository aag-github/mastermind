#ifndef SRC_VIEWS_SAVEGAMEVIEW_H_
#define SRC_VIEWS_SAVEGAMEVIEW_H_

#include <algorithm>
#include <iostream>
#include "SaveGameController.h"
#include "DialogReadString.h"
#include "ui/DialogYesNoView.h"
#include "ui/AvailableGamesView.h"

namespace Mastermind {

class SaveGameView {
public:
    SaveGameView(){
    };

    virtual ~SaveGameView(){
    };

    void interact(SaveGameController* controller){
        assert(controller != nullptr);

        auto availableGames = controller->getAvailableGames();

        AvailableGamesView(availableGames).show();

        std::string name = IO::DialogReadString("\nGame name to save: ").read();

        if (std::find(availableGames.begin(), availableGames.end(), name) != availableGames.end()) {
            if(!DialogYesNoView().read("\nThe file already exists, do you want to overwrite it? (Y/N)")) {
                return;
            }
        }

        if (0 != controller->save(name)) {
            std::cout << "\n** Error saving file " << name << "**";
        }
        printf("\n");
    }
};

}
#endif
