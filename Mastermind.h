#ifndef _MASTERMIND_H
#define _MASTERMIND_H

#include <time.h>
#include <cstdlib>

namespace Mastermind
{

class Mastermind {
private:

public:
    Mastermind()
    {
        srand(time(nullptr));
    };

    void play()
    {
    }
};

}
#endif
