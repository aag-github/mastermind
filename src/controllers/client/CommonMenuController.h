#ifndef SRC_CONTROLLERS_COMMONMENUCONTROLLER_H_
#define SRC_CONTROLLERS_COMMONMENUCONTROLLER_H_

#include <assert.h>
#include "CombinationController.h"

#include "QuitController.h"

namespace Mastermind {

class CommonMenuController: public QuitController
{
public:
    CommonMenuController(Game &game) :
        quitController(game)
    {
    }

    virtual ~CommonMenuController(){
    }


    virtual void quit(bool quit) override final {
        quitController.quit(quit);
    }


private:
    QuitControllerImpl quitController;
};

}

#endif
