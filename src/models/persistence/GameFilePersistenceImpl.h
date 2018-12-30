#ifndef SRC_MODELS_GAMEFILEPERSISTENCE_H_
#define SRC_MODELS_GAMEFILEPERSISTENCE_H_

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <dirent.h>

namespace Mastermind {

class GameFilePersistenceImpl : public GamePersistenceImpl {
public:
    GameFilePersistenceImpl(){};
    virtual ~GameFilePersistenceImpl(){};

    virtual std::vector<std::string> getAvailableGames() const override final {
        std::vector<std::string> availableGames;
        const std::string extension(".mm");
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir (".")) != nullptr) {
          while ((ent = readdir (dir)) != nullptr) {
            if (ent->d_type == DT_REG) {
                std::string name(ent->d_name);
                size_t extenstionPosition = name.find(extension);
                if (extenstionPosition == (name.size() - extension.size())) {
                    name = name.substr(0, extenstionPosition);
                    if (name != "") {
                        availableGames.push_back(name);
                    }
                }
            }
          }
          closedir (dir);
        }
        return availableGames;
    }

    virtual GamePersistenceResult load(Game* game, const std::string& name) override final {
        GamePersistenceResult ret = GamePersistenceResult::OK;

        std::ifstream file(name + ".mm" , std::ios::in);

        if (!file.is_open()) {
            return GamePersistenceResult::OPEN_FILE_ERROR;
        }

        game->start();

        std::string line;

        std::shared_ptr<Memento> memento = std::make_shared<Memento>();

        while(!file.eof()) {
            std::getline(file, line);

            memento->add(line);
        }

        file.close();

        game->restoreMemento(memento, true);

        return ret;
    }

    virtual GamePersistenceResult save(const Game* game, const std::string& name) const override final{
        GamePersistenceResult ret = GamePersistenceResult::OK;

        FILE *fp = fopen((name + ".mm").c_str(), "w");

        if (!fp) {
            return GamePersistenceResult::OPEN_FILE_ERROR;
        }

        std::shared_ptr<Memento> memento = game->createMemento();

        fprintf(fp, "%s", memento->toString().c_str());

        fclose(fp);
        return ret;
    }
};

}

#endif
