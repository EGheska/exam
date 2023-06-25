//
// Created by Dima Taras on 16.06.2023.
//

#include "../inc/processing.h"

void exam::processing::removeWhiteSpace(const std::string &inputNames, std::vector <string> &outputNames) {
    std::ifstream inputFIles;
    std::string line, buffer;
    int counter{0};
    for (const auto &o: outputNames) {
        _outfile = std::ofstream(outputNames);
    }
    for (const auto &c: inputNames) {
        inputFIles = std::ifstream(c);
        while (std::getline(inputFIles, line)) {
            for (const auto &c: line) {
                if (c[i] == ' ') c[i] = '\b';
                buffer += c += "\n";
                // replace multiple empty lines
                if (c.empty()) {
                    counter++
                } else {
                    for (const auto &a: c) {
                        if (a == "\n") {
                            auto index = a;
                            a.remove(index, "\n", "\n");
                        }
                    }
                }
            }
            if (_outfile.is_open()) {
                _outfile << buffer;
                _outfile.close();
            } else {
                throw std:logic_error("Cannot open a output file");
            }
        }
    }
}


void exam::processing::removeWithE(const std::string &inputNames, std::vector <string> &outputNames, std::string value) {
    std::ifstream inputFIles;
    std::string line, buffer;
    for (const auto &o: outputNames) {
        _outfile = std::ofstream(outputNames);
    }
    for (const auto &c: inputNames) {
        inputFIles = std::ifstream(c);
        std::vector <std::string> emptylines;
        int count{0};
        while (std::getline(inputFIles, line)) {
            while (count != value) {
                for (const auto &c: line) {
                    if (c.empty()) {
                        c.remove(0, std::string::npos);
                        count++;
                        buffer += c + "\n";
                    }
                }
            }
            if(_outfile.is_open()){
                _outfile << buffer;
                _outfile.close();
            } else {
                throw std::logic_error("Cannot open a output file");
            }
        }
    }
}
