//
// Created by Patrick on 12/5/2018.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "day5.h"

std::vector<char> const day5::get_inputs() {
    std::fstream in;
    in.open("../day5/day5.txt");

    std::vector<char> inputs{std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>()};

    return inputs;
}

int day5::get_size_of_polymer(const std::vector<char> &v) {
    std::vector<char> copy{v};

    while (true) {
        bool is_triggered = false;
        for (auto curr_char = copy.begin() + 1; curr_char != copy.end();) {
            auto prev_char = curr_char - 1;

            if ((*curr_char ^ *prev_char) == 32) {
                is_triggered = true;
                curr_char = copy.erase(prev_char, curr_char + 1);
            } else {
                ++curr_char;
            }
        }

        if (!is_triggered) return static_cast<int>(copy.size());
    }
}


int day5::find_size_of_shortest_polymer(const std::vector<char> &polymers) {
    const std::vector<char> chars_to_check{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                           'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    auto min = polymers.size();
    for (const auto &char_to_check: chars_to_check) {
        auto copy{polymers};
        copy.erase(std::remove(copy.begin(), copy.end(), char_to_check), copy.end());
        copy.erase(std::remove(copy.begin(), copy.end(), toupper(char_to_check)), copy.end());
        const auto size = get_size_of_polymer(copy);
        if (size < min) min = size;
    }

    return min;
}