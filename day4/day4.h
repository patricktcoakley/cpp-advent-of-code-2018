//
// Created by Patrick on 12/4/2018.
//

#include <string>
#include <set>
#include <regex>

#ifndef AOC2018_DAY4_H
#define AOC2018_DAY4_H

#endif //AOC2018_DAY4_H

namespace day4 {

    int find_guard_with_most_minutes_asleep(const std::set<std::string> &reports);

    std::set<std::string> get_inputs();

    constexpr double
    compare_guard_sleep(const std::pair<std::string, double> &pair1, const std::pair<std::string, double> &pair2);

    constexpr int compare_sleep_time(const std::pair<int, int> &pair1, const std::pair<int, int> &pair2);

    bool is_beginning_shift(const std::string &s, const std::regex &guard_begins_regex);

    bool is_awake(const std::string &s, const std::regex &guard_awake_regex);

    bool is_falling_asleep(const std::string &s, const std::regex &guard_asleep_regex);

    const std::string get_id(const std::string &s, const std::regex &guard_id_regex);

    std::time_t get_date_time(const std::string &s, const std::regex &date_regex);

    int get_minute(const std::string &s, const std::regex &date_regex);

    int find_most_frequently_asleep_guard(std::set<std::string> reports);
}