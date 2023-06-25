#include "inc/num_vector.h"
#include "inc/options.h"
#include "inc/processing.h"
#include <iostream>

/**
 * Demonstrates the working of num_vector
 */
void demo_num_vector(){
    using namespace exam;

    num_vector vec1{1.0, 2.0, 3.0, 4.0};

    vec1.append(42);

    num_vector vec2{9.0, 7.0, 5.0, 3.0, 1.0};

    vec2 += 5;

    vec2 += vec1;

    std::cout << vec1 << '\n';
    std::cout << vec2 << '\n';
}

int main(int argc , char * argv[]) {

    //  options are input files
    // [in.txt in2.txt in3.txt]
    // programm removes whitespaces

    demo_num_vector();

    exam::options opts(argc, argv);
    exam::processing process;
    for (const auto &c: opts.returnInputFileNames()) {
        auto outputFileNames = opts.returnOutputFileNames();
        process.removeWhiteSpace(c, outputFileNames);
        if (opts.is_e_opts()) {
            process.removeWithE(c, outputFileNames, opts.returnValue());
        }
    }
}