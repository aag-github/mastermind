#ifndef SRC_VIEWS_COMMANDS_SHOWMENUVIEW_H_
#define SRC_VIEWS_COMMANDS_SHOWMENUVIEW_H_

#include "ui/ViewConst.h"
#include "ui/CommandView.h"

namespace Mastermind {

class ShowMenuView {
public:
    ShowMenuView(std::vector<CommandView*> *commands, std::string title, const CommandView* defaultCommand = nullptr) :
        commands(commands),
        title(title),
        defaultCommand(defaultCommand)
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

    const CommandView *defaultCommand;

    void show() const {
        int i = 1;
        std::cout << std::endl << SECTION_BREAK << std::endl;
        for(auto command : *commands) {
            std::stringstream itemNumber;
            command->show(std::to_string(i), command == defaultCommand);
            i++;
        }
        std::cout << std::endl;
        std::cout << title << std::endl;
    }

    int read() const {
        std::string options = "1234567";
        int defaultOption = 0;
        int i = 1;
        for(auto command : *commands) {
            if (command == defaultCommand) {
                defaultOption = i;
                break;
            }
            i++;
        }

        if (defaultOption != 0) {
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
