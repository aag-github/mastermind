#ifndef SRC_VIEWS_COMMANDS_COMMANDVIEW_H_
#define SRC_VIEWS_COMMANDS_COMMANDVIEW_H_

#include "client/MenuController.h"

namespace Mastermind {

class MenuController;

class CommandView {
public:
    virtual ~CommandView(){};
    virtual void execute() = 0 ;
    virtual void show(std::string prefix, bool defaultOption ) = 0;
};

template <class VIEW, class CONTROLLER> class CommandViewTemplate : public CommandView {
public:
    CommandViewTemplate(std::string title, VIEW *view, CONTROLLER *controller) :
        title(title),
        view(view),
        controller(controller)
    {

    };

    virtual ~CommandViewTemplate(){};

    virtual void execute() override final {
           assert(controller != nullptr);
           assert(view != nullptr);

           view->interact(controller);
       }

    virtual void show(std::string prefix, bool defaultOption) override {
        std::cout << " ";
        if (!prefix.empty()) {
            std::cout << prefix << ".- ";
        }
        if (defaultOption) {
            std::cout << "[" << title << "]" << std::endl;
        } else {
            std::cout << title << std::endl;
        }
    }
private:
    std::string title;
    VIEW *view;
    CONTROLLER *controller;
};

}

#endif
