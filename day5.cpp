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
    in.open("../day5.txt");

    while (std::getline(in, inputs));

    in.close();
    return inputs;
}

int day5::get_size_of_polymer(std::string s) {
    bool done = false;

    while (!done) {
        for (int next_char_index = 1; next_char_index != s.size(); ++next_char_index) {
            int current_char_index = next_char_index - 1;
            bool is_triggered = (s[current_char_index] ^ s[next_char_index]) == 32;

            if (is_triggered) {
                s.erase(current_char_index, 2);
                next_char_index = 0;
            }
        }

        done = true;
    }
    return s.length();
}

int day5::find_size_of_shortest_polymer(std::string s) {
    std::vector<char> chars_to_check{'a', 'b', 'c', 'd'};
    std::vector<std::string> strings;
    auto min = s.size();


    for (const auto &c: chars_to_check) {
        auto temp_string = s;
        temp_string.erase(std::remove(temp_string.begin(), temp_string.end(), c), temp_string.end());
        temp_string.erase(std::remove(temp_string.begin(), temp_string.end(), (c & ~32)), temp_string.end());
        strings.push_back(temp_string);
    }

    for (const auto &str: strings) {
        int size = get_size_of_polymer(str);
        if (size < min) min = size;
    }

    return min;
}


