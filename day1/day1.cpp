//
// Created by Patrick on 12/1/2018.
//

#include <fstream>
#include <numeric>
#include <unordered_map>
#include "day1.h"

const std::vector<int> day1::get_inputs() {
    std::vector<int> output;
    std::fstream in;
    in.open("inputs/day1.txt");

    for (std::string line; std::getline(in, line);) {
        if (line[0] == '-') {
            output.push_back(std::stoi(line));
        } else {
            output.push_back(std::stoi(line.substr(1)));
        }
    }

    return output;
}

int day1::sum_of_frequencies(const std::vector<int> &frequencies) {
    return std::accumulate(frequencies.begin(), frequencies.end(), 0);
}

int day1::get_first_duplicate_frequency(const std::vector<int> &frequencies) {
    std::unordered_map<int, int> frequency_map;
    int current_total = 0;
    for (;;) {
        for (const auto &frequency: frequencies) {
            current_total += frequency;
            frequency_map[current_total] += 1;
            if (frequency_map[current_total] == 2) return current_total;
        }
    }
}


