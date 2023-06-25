//
// Created by Dima Taras on 16.06.2023.
//

#include <string>
#include "../inc/options.h"

exam::options::options(int argc, char **argv) {
    parse(argc, argv);
}

bool exam::options::is_e_opts() const {
    return _is_e_opt;
}

std::vector <std::string> exam::options::returnInputFileNames() const {
    return _inputFileNames;
}

void exam::options::parse(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        std::string args(argv[i]);
        if (args == "-e") {
            _is_e_opt = true;
            _value = argv[++i];
        } else if (!args.starts_with("-")) {
            auto inpname = args;
            _inputFileNames.push_back(args);
            _outputFileNames.push_back("cleaned_" + inpname);
        }
    }

}

std::string exam::options::returnValue() const {
    return _value;
}

std::vector <string> exam::options::returnOutputFileNames() const {
    return _outputFileNames;
}
