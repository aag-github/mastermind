#include "Mastermind.h"

int main(int argc, char *argv[])
{
    Mastermind::ArgParser parser(argc, argv);

    Mastermind::Mastermind *mastermind = Mastermind::Mastermind::build(parser);

    mastermind->play();

    delete mastermind;

    return 0;
}


