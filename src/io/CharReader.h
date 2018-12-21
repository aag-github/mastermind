#ifndef SRC_GETCH_H_
#define SRC_GETCH_H_

#include <assert.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "CharChecker.h"

namespace IO
{

class CharReader {
private:
    static int kbhit(void)
    {
      struct termios oldt, newt;
      int ch;
      int oldf;

      tcgetattr(STDIN_FILENO, &oldt);
      newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
      fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

      ch = getchar();

      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      fcntl(STDIN_FILENO, F_SETFL, oldf);

      if(ch != EOF)
      {
        ungetc(ch, stdin);
        return 1;
      }

      return 0;
    }

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
        while (kbhit()){
            getchar();
            ch = 0;
        }
        return ch;
    }

public:
    static int read(CharChecker *charChecker = nullptr) {
        if (!charChecker) {
            return getch();
        } else {
            int c = 0;
            do {
                c = charChecker->getValidChar(getch());
            } while (!c);
            return c;
        }
    }

};

}
#endif
