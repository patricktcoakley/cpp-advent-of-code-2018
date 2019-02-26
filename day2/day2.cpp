//
// Created by Patrick on 12/1/2018.
//

#include <algorithm>
#include <fstream>
#include <unordered_map>
#include "day2.h"

const std::vector<std::string> day2::get_inputs() {
    std::vector<std::string> inputs;
    std::fstream in;
    in.open("inputs/day2.txt");

    for (std::string line; std::getline(in, line);)
        inputs.push_back(line);

    in.close();
    std::sort(inputs.begin(), inputs.end());
    return inputs;
}

int day2::checksum(const std::vector<std::string> &box_ids) {
    int doubles = 0;
    int triples = 0;

    for (const auto &line: box_ids) {
        std::unordered_map<char, int> frequency;
        bool has_double = false;
        bool has_triple = false;

        for (const char &c: line) frequency[c] += 1;

        for (const char &c: line) {
            if (frequency[c] == 2 && !has_double) {
                ++doubles;
                has_double = true;
            }
            if (frequency[c] == 3 && !has_triple) {
                ++triples;
                has_triple = true;
            }
        }
    }
    return doubles * triples;
}

const std::string day2::find_common_letters(const std::vector<std::string> &box_ids) {

    for (std::size_t line = 0; line != box_ids.size(); ++line) {
        unsigned int diff_chars = 0;
        unsigned int common_char_pos = 0;
        auto current_string = box_ids[line];
        auto next_string = box_ids[line + 1];

        for (unsigned int current_char = 0; current_char != box_ids[line].size(); ++current_char) {
            if (current_string.at(current_char) != next_string.at(current_char)) {
                ++diff_chars;
                common_char_pos = current_char;
            }
        }
        if (diff_chars == 1) return current_string.erase(common_char_pos, 1);
    }
    return "No similar strings found.";
}
