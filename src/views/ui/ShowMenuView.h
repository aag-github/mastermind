#ifndef SRC_VIEWS_COMMANDS_SHOWMENUVIEW_H_
#define SRC_VIEWS_COMMANDS_SHOWMENUVIEW_H_

#include "ui/ViewConst.h"
#include "ui/CommandView.h"

namespace Mastermind {

class ShowMenuView {
public:
    ShowMenuView(std::vector<CommandView*> *commands, std::string title, unsigned defaultOption = 0) :
        commands(commands),
        title(title),
        defaultOption(defaultOption)
    {

    }

    virtual ~ShowMenuView() {}

    int execute() const {
        show();
        return read();
    }
private:
    std::vector<CommandView*> *commands;

    std::string title;

    int defaultOption;

    void show() const {
        int i = 1;
        std::cout << std::endl << SECTION_BREAK << std::endl;
        for(auto command : *commands) {
            std::stringstream itemNumber;
            command->show(std::to_string(i));
            i++;
        }
        std::cout << std::endl;
        std::cout << title << std::endl;
    }

    int read() const {
        std::string options = "1234567";
        if (defaultOption > 0) {
            options += "\n";
        }
        IO::CharChecker charChecker(options);
        int option = IO::CharReader::read(&charChecker);

        if (option == '\n') {
            option = defaultOption;
        } else {
            option = option - '0';
        }
        return option;
    }
};

}

#endif
