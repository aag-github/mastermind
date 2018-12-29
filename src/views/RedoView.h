#ifndef SRC_VIEWS_REDOVIEW_H_
#define SRC_VIEWS_REDOVIEW_H_

#include "RedoController.h"

namespace Mastermind {

class RedoView {
public:
    RedoView(){
    };

    virtual ~RedoView(){
    };

    void interact(RedoController* controller){
        assert(controller != nullptr);

        controller->redo();
        printf("\n");
    }
};

}
#endif
