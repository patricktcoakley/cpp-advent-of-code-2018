//
// Created by Patrick on 12/1/2018.
//

#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <iostream>
#include <set>
#include "day2.h"

const std::vector<std::string> day2::get_inputs() {
    std::vector<std::string> inputs;
    std::fstream in;
    in.open("inputs/day2.txt");

    for (std::string line; std::getline(in, line);)
        inputs.push_back(line);

    std::sort(inputs.begin(), inputs.end());
    return inputs;
}

int day2::checksum(const std::vector<std::string> &box_ids) {
    int doubles = 0;
    int triples = 0;

    for (const auto &line: box_ids) {
        bool has_double = false;
        bool has_triple = false;

        for (const auto &c: std::set<char>{line.begin(), line.end()}) {
            auto count = std::count(line.begin(), line.end(), c);

            if (count == 2 && !has_double) {
                doubles += 1;
                has_double = true;
            } else if (count == 3 && !has_triple) {
                triples += 1;
                has_triple = true;
            }
        }
    }

    return doubles * triples;
}

const std::string day2::find_common_letters(const std::vector<std::string> &box_ids) {

    auto current = box_ids.begin();
    auto next = box_ids.begin() + 1;
    auto length_to_check = current->length() - 1;

    while (next != box_ids.end()) {
        std::string result{};
        std::set_intersection(current->begin(), current->end(), next->begin(), next->end(), std::back_inserter(result));
        if (result.length() == length_to_check) return result;
        ++current, ++next;
    }

    return "No similar strings found.";
}
