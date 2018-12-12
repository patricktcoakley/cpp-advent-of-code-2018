//
// Created by Patrick on 12/4/2018.
//

#include <fstream>
#include "day4.h"

std::vector<std::string> day4::get_inputs() {
    std::vector<std::string> inputs;
    std::fstream in;
    in.open("../day4.txt");

    for (std::string line; std::getline(in, line);)
        inputs.push_back(line);

    in.close();
    return inputs;
}
