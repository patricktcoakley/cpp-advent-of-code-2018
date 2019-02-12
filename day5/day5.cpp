//
// Created by Patrick on 12/5/2018.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <thread>
#include <stack>
#include "day5.h"

std::vector<char> const day5::get_inputs() {
    std::fstream in;
    in.open("../day5/day5.txt");

    std::vector<char> inputs{std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>()};

    return inputs;
}

int day5::get_size_of_polymer(const std::vector<char> &polymers) {
    std::stack<char> polymer_stack;

    for (char polymer : polymers) {
        if (polymer_stack.empty()) {
            polymer_stack.push(polymer);
        } else if ((polymer ^ polymer_stack.top()) == 32) {
            polymer_stack.pop();
        } else {
            polymer_stack.push(polymer);
        }
    }
    return static_cast<int>(polymer_stack.size());
}


int day5::find_size_of_shortest_polymer(const std::vector<char> &polymers) {

    const std::vector<char> chars_to_check{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                           'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    int min = static_cast<int>(polymers.size());

    for (const auto &char_to_check: chars_to_check) {
        const auto clean_polymers = [char_to_check](auto c) { return c == char_to_check || c == toupper(char_to_check); };
        auto copy{polymers};
        copy.erase(std::remove_if(copy.begin(), copy.end(), clean_polymers), copy.end());
        min = std::min(min, get_size_of_polymer(copy));
    }

    return min;
}