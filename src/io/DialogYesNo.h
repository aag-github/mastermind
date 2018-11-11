#ifndef SRC_IO_DIALOGYESNO_H_
#define SRC_IO_DIALOGYESNO_H_

#include <string>
#include "CharReader.h"

namespace Mastermind {

class DialogYesNo {
public:
    DialogYesNo(std::string title) :
        title(title)
    {
    }

    virtual ~DialogYesNo(){
    }

    bool read() const {
        printf("%s", title.c_str());

        IO::CharUpperCaseChecker charChecker("YN");
        int option = IO::CharReader::read(&charChecker);

        return option == 'Y';
    }

private:
    std::string title;
};

}

#endif
