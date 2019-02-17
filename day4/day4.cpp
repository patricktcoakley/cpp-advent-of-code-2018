//
// Created by Patrick on 12/4/2018.
//

#include <fstream>
#include <regex>
#include <iostream>
#include <ctime>
#include "day4.h"

std::set<std::string> day4::get_inputs() {
    std::set<std::string> inputs;
    std::fstream in;
    in.open("inputs/day4.txt");

    for (std::string line; std::getline(in, line);)
        inputs.insert(line);

    return inputs;
}

int day4::find_guard_who_slept_most(const std::set<std::string> &s) {
    std::map<std::string, int> guard_sleep_map;

    const std::regex guard_id_regex{R"((\#(\d+)))"};
    const std::regex guard_awake_regex{R"((\bwakes\b))"};
    const std::regex guard_asleep_regex{R"((\bfalls\b))"};
    const std::regex date_regex{R"(\[(.+)\])"};

    auto sleep_difference = [](auto time1, auto time2){return time1 - time2;};
    auto is_awake = [&](auto s) -> bool {return std::regex_search(s, guard_awake_regex);};
    auto is_asleep = [&](auto s) -> bool {return std::regex_search(s, guard_asleep_regex);};


    auto get_id = [&](auto string) {
        std::smatch matches;
        std::regex_search(string, matches, guard_id_regex);
        std::cout << matches[0] << std::endl;
    };

    std::smatch m;
    std::deque<std::string> sleep_queue;
    for (auto &l: s) {

    }


    return 0;
}
