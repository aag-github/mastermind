#ifndef SRC_VIEWS_UI_AVAILABLEGAMESVIEW_H_
#define SRC_VIEWS_UI_AVAILABLEGAMESVIEW_H_

namespace Mastermind {

class AvailableGamesView {
public:
    AvailableGamesView(std::vector<std::string> availableGames) :
        availableGames(availableGames)
    {
    }

    virtual ~AvailableGamesView() {}

    void show() const {
        std::cout << "\n";

        if (availableGames.size() == 0) {
            std::cout << "** No games available **\n";
            return;
        }
        std::cout << "Available games:\n" << SECTION_BREAK << "\n";
        for(auto name : availableGames) {
            std::cout << name << "\n";
        }
        std::cout << SECTION_BREAK << "\n";
    }
private:
    std::vector<std::string> availableGames;
};

}

#endif
