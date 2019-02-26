//
// Created by patrick on 2/21/19.
//

#include <fstream>
#include <regex>
#include <iostream>
#include "day6.h"

const std::set<std::pair<int, int>> day6::get_inputs() {
    const std::regex input_regex{R"(((\d+),\s+(\d+)))"};
    std::set<std::pair<int, int>> inputs;
    std::fstream in;
    in.open("inputs/day6.txt");

    for(std::string line; std::getline(in, line); ) {
        std::smatch s;
        std::regex_search(line, s, input_regex);
        inputs.insert(std::pair{std::stoi(s[2]), std::stoi(s[3])});
    }

    return inputs;

}

int day6::find_largest_area(const std::set<std::pair<int, int>> &pairs) {
    return pairs.size();
}
