#ifndef SRC_ARGPARSER_H_
#define SRC_ARGPARSER_H_

#include <string>
#include <stdio.h>
#include "ExecMode.h"

namespace Mastermind {

class ArgParser {
public:
    ArgParser(int argc, char *argv[]) :
        execMode(ExecMode::STANDALONE),
        ip("127.0.0.1"),
        port(5555)
    {
        parse(argc, argv);
    }
    virtual ~ArgParser() {}

    void parse(int argc, char *argv[]) {
        int current = 1;
        while(current < argc) {
            if (std::string(argv[current]) == "-c") {
                execMode = ExecMode::CLIENT;
            } else if (std::string(argv[current]) == "-s") {
                execMode = ExecMode::SERVER;
            } else if (std::string(argv[current]) == "-p") {
                if (++current < argc) {
                    port = atoi(argv[current]);
                }
            } else if (std::string(argv[current]) == "-i") {
                if (++current < argc) {
                    ip = argv[current];
                }
            }
            ++current;
        }
    }

    ExecMode getExecMode() const {
        return execMode;
    }

    std::string getIp() const {
        return ip;
    }

    int getPort() const {
        return port;
    }

private:
    ExecMode execMode;
    std::string ip;
    int port;
};

}

#endif
