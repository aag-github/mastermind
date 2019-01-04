#ifndef SRC_VIEWS_COMMANDS_SHOWMENUVIEW_H_
#define SRC_VIEWS_COMMANDS_SHOWMENUVIEW_H_

#include "client/commands/CommandView.h"

namespace Mastermind {

class ShowMenuView {
public:
    ShowMenuView(std::vector<CommandView*> *commands) :
        commands(commands)
    {

    }

    virtual ~ShowMenuView() {}

    int execute() const {
        show();
        return read();
    }
private:
    std::vector<CommandView*> *commands;


    void show() const {
        int i = 1;
        std::cout << std::endl << SECTION_BREAK << std::endl;
        for(auto command : *commands) {
            std::stringstream itemNumber;
            command->show(std::to_string(i));
            i++;
        }
        std::cout << std::endl;
        std::cout << "Pick an option or press 'Enter' to type a new combination" << std::endl;
    }

    int read() const {
        IO::CharChecker charChecker("1234567\n");
        int option = IO::CharReader::read(&charChecker);
        if (option == '\n') {
            option = '5';
        }
        option = option - '0';
        return option;
    }
};

}

#endif
