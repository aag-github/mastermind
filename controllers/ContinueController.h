#ifndef SRC_CONTROLLERS_CONTINUECONTROLLER_H_
#define SRC_CONTROLLERS_CONTINUECONTROLLER_H_

#include "../io/CharReader.h"
#include "OperationController.h"

namespace Mastermind {

class ContinueController: public OperationController {
public:
    ContinueController(Game &game) :
        OperationController(game)
    {
    }

    virtual ~ContinueController(){
    }

    void control() {
        printf("Play again (Y/N)?\n");

        IO::CharUpperCaseChecker charChecker("YN");
        int option = IO::CharReader::Read(&charChecker);

        if (toupper(option) == 'Y') {
            setState(State::INITIAL);
        } else {
            setState(State::EXIT);
        }
    };
};

}

#endif
