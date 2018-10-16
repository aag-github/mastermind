#ifndef SRC_GETCH_H_
#define SRC_GETCH_H_

#include <assert.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "CharChecker.h"

namespace IO
{

class CharReader {
private:
    static int getch(void)
    {
        struct termios oldattr, newattr;
        int ch;
        tcgetattr( STDIN_FILENO, &oldattr );
        newattr = oldattr;
        newattr.c_lflag &= ~( ICANON | ECHO );
        tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
        ch = getchar();
        tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
        return ch;
    }

public:
    static int read() {
        return getch();
    }

    static int read(CharChecker *charChecker) {
        assert(charChecker);
        int c = 0;
        do {
            c = charChecker->getValidChar(getch());
        } while (charChecker && !c);
        return c;
    }

};

}
#endif
