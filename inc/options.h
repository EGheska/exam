//
// Created by Dima Taras on 16.06.2023.
//

#ifndef EXAM_2023_II_OPTIONS_H
#define EXAM_2023_II_OPTIONS_H


#include <vector>

namespace exam {


    class options {
    public:
        options(int argc, char *argv[]);

        //Accessor

        bool is_e_opts() const;
        // Getter & Setter
        std::string returnValue() const;

        std::vector <std::string> returnInputFileNames() const;

        std::vector <std::string> returnOutputFileNames() const;
        // Member function
        void parse(int argc, char *argv[]);

    private:
        bool _is_e_opt;
        std::string _value;
        std::vector <std::string> _inputFileNames;
        std::vector <std::string> _outputFileNames;
    };
}