//
// Created by Dima Taras on 16.06.2023.
//

#ifndef EXAM_2023_II_PROCESSING_H
#define EXAM_2023_II_PROCESSING_H

#include <string>
#include <fstream>

namespace exam {

    class processing {
    public:
        // default constructor since no parameters passed,
        // and since this one is not really needed but
        // it should be marked it with default
        processing() = default;

        void removeWhiteSpace(const std::string &inputNames, std::vector <std::string> &outputNames);
        void removeWithE(const std::string &inputNames, std::vector <std::string> &outputNames, std::string value);

    private:
        std::ofstream _outfile;
    };

}
#endif //EXAM_2023_II_PROCESSING_H
