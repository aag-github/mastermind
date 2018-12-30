#ifndef SRC_VIEWS_SECRETCOMBINATIONVIEW_H_
#define SRC_VIEWS_SECRETCOMBINATIONVIEW_H_

#include "CombinationView.h"

namespace Mastermind {

class SecretCombinationView : public CombinationView {
public:
    SecretCombinationView(const Combination *combination) :
        CombinationView(combination)
    {
    }

    virtual ~SecretCombinationView(){
    };

 /*   virtual void showColor(const ColorList::Color &color) const {
        printf("X ");
    }*/
};

}

#endif
