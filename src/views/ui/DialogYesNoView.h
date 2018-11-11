#ifndef SRC_VIEWS_CONSOLE_DIALOGYESNOVIEW_H_
#define SRC_VIEWS_CONSOLE_DIALOGYESNOVIEW_H_

#include "DialogYesNo.h"

namespace Mastermind {

class DialogYesNoView {
public:
    DialogYesNoView(){
    }

    virtual ~DialogYesNoView(){
    }

    bool read(std::string title) const {
        return DialogYesNo(title).read();
    }
};

}

#endif
