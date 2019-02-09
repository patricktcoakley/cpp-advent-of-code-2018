//
// Created by Patrick on 12/5/2018.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include "day5.h"

std::string day5::get_inputs() {
    std::string inputs;
    std::fstream in;
    in.open("../day5/day5.txt");

    while (std::getline(in, inputs));

    return inputs;
}

int day5::get_size_of_polymer(std::string s) {
    bool done = false;

    while (!done) {
        for (unsigned int next_char_index = 1; next_char_index != s.size(); ++next_char_index) {
            unsigned int current_char_index = next_char_index - 1;
            bool is_triggered = (s[current_char_index] ^ s[next_char_index]) == 32;

            if (is_triggered) {
                s.erase(current_char_index, 2);
                next_char_index = 0;
            }
        }

        done = true;
    }
    return static_cast<int>(s.length());
}


void day5::erase_chars_from_vector(const std::string &s, std::vector<int> &sizes, const char &c) {
    auto temp_string = s;
    temp_string.erase(remove(temp_string.begin(), temp_string.end(), c), temp_string.end());
    temp_string.erase(remove(temp_string.begin(), temp_string.end(), (c & ~32)), temp_string.end());

    auto size = get_size_of_polymer(temp_string);
    sizes.push_back(size);
}


int day5::find_size_of_shortest_polymer(std::string s) {
    const std::vector<char> chars_to_check{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                     'o', 'p', 'q', 'r', 's', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'x'};

    std::vector<int> sizes;

    for (const auto &c: chars_to_check) erase_chars_from_vector(s, sizes, c);

    return *std::min_element(sizes.begin(), sizes.end());
}