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
                    availableGames.push_back(name.substr(0, extenstionPosition));
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

        while(!file.eof()) {
            std::getline(file, line);

            if  (line == "") {
                continue;
            }

            auto separator = line.find(':');
            std::string command = line.substr(0, separator);
            std::string value = line.substr(separator +1);

            if (command == "S") {
                SecretCombination secret;
                if (value.size() != secret.size())
                {
                    ret = GamePersistenceResult::SECRET_COMBINATION_ERROR;
                    break;
                }
                secret = value;
                game->setSecretCombination(secret);
            } else if (command =="P") {
                Combination combination;
                if (value.size() != combination.size())
                {
                    ret = GamePersistenceResult::PROPOSED_COMBINATION_ERROR;
                    break;
                }
                combination = value;
                game->setProposedCombination(combination);
            }
        }

        file.close();
        return ret;
    }

    virtual GamePersistenceResult save(const Game* game, const std::string& name) const override final{
        GamePersistenceResult ret = GamePersistenceResult::OK;

        FILE *fp = fopen((name + ".mm").c_str(), "w");

        if (!fp) {
            return GamePersistenceResult::OPEN_FILE_ERROR;
        }

        fprintf(fp, "S:%s\n", game->getSecretCombination().getString().c_str());
        auto combination = game->getProposedCombinations().cbegin();
        auto endCombination = game->getProposedCombinations().cend();
        for (;combination != endCombination, combination->isSet(); combination++) {
            fprintf(fp, "P:%s\n", combination->getString().c_str());
        }

        fclose(fp);
        return ret;
    }
};

}

#endif