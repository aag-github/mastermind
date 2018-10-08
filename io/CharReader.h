#ifndef SRC_GETCH_H_
#define SRC_GETCH_H_

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

    static int ReadSingleCharacter(CharChecker *charChecker) {
        int c;
        do {
            c = getch();
            c = charChecker->getValidChar(c);
        } while (charChecker && !c);
        return c;
    }
public:
    static int Read(CharChecker *charChecker = nullptr) {
        return ReadSingleCharacter(charChecker);
    }

};

}
#endif
