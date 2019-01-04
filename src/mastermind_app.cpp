#include "MastermindBuilder.h"
#include "Mastermind.h"

int main(int argc, char *argv[])
{
    Mastermind::ArgParser parser(argc, argv);

    Mastermind::MastermindPlayer *mastermind = Mastermind::MastermindBuilder::instance()->build(parser);

    mastermind->play();

    delete mastermind;

    Mastermind::MastermindBuilder::cleanup();

    return 0;
}


