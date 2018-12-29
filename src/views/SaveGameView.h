#ifndef SRC_VIEWS_SAVEGAMEVIEW_H_
#define SRC_VIEWS_SAVEGAMEVIEW_H_

#include <iostream>
#include "SaveGameController.h"
#include "DialogReadString.h"

namespace Mastermind {

class SaveGameView {
public:
    SaveGameView(){
    };

    virtual ~SaveGameView(){
    };

    void interact(SaveGameController* controller){
        assert(controller != nullptr);

        std::string name = IO::DialogReadString("\nGame name to save: ").read();

        if (0 != controller->save(name)) {
            std::cout << "\n** Error saving file " << name << "**";
        }
        printf("\n");
    }
};

}
#endif
