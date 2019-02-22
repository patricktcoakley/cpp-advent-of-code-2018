//
// Created by Patrick on 12/4/2018.
//

#include <fstream>
#include <unordered_map>
#include <iostream>
#include "day4.h"

std::set<std::string> day4::get_inputs() {
    std::set<std::string> inputs;
    std::fstream in;
    in.open("inputs/day4.txt");

    for (std::string line; std::getline(in, line);) inputs.insert(line);

    return inputs;
}

constexpr double
day4::compare_guard_sleep(const std::pair<std::string, double> &pair1, const std::pair<std::string, double> &pair2) {
    return pair1.second < pair2.second;
}

constexpr int day4::compare_sleep_time(const std::pair<int, int> &pair1, const std::pair<int, int> &pair2) {
    return pair1.second == pair2.second ? pair1.first < pair2.first : pair1.second < pair2.second;
}

bool day4::is_beginning_shift(const std::string &s, const std::regex &guard_begins_regex) {
    return std::regex_search(s, guard_begins_regex);
}

bool day4::is_awake(const std::string &s, const std::regex &guard_awake_regex) {
    return std::regex_search(s, guard_awake_regex);
}

bool day4::is_falling_asleep(const std::string &s, const std::regex &guard_asleep_regex) {
    return std::regex_search(s, guard_asleep_regex);
}

const std::string day4::get_id(const std::string &s, const std::regex &guard_id_regex) {
    std::smatch matches;
    std::regex_search(s, matches, guard_id_regex);
    return matches[0];
}

std::time_t day4::get_date_time(const std::string &s, const std::regex &date_regex) {
    std::tm date{};
    std::smatch matches;
    std::regex_search(s, matches, date_regex);
    const auto format = "[%Y-%m-%d %H:%M]";
    strptime(matches[0].str().c_str(), format, &date);
    date.tm_year += 500; // year is pre-epoch UNIX time and therefore should be increased equally
    return mktime(&date);
}

int day4::get_minute(const std::string &s, const std::regex &date_regex) {
    std::tm date{};
    std::smatch matches;
    std::regex_search(s, matches, date_regex);
    const auto format = "[%Y-%m-%d %H:%M]";
    strptime(matches[0].str().c_str(), format, &date);
    return date.tm_min;
}


int day4::find_guard_with_most_minutes_asleep(const std::set<std::string> &reports) {
    std::unordered_map<std::string, double> guard_sleep_map;

    const std::regex guard_awake_regex{R"((\bwakes\b))"};
    const std::regex guard_begins_regex{R"((\bbegins\b))"};
    const std::regex guard_asleep_regex{R"((\bfalls\b))"};
    const std::regex date_regex{R"(\[(.+)\])"};
    const std::regex guard_id_regex{R"((\#(\d+)))"};

    std::time_t sleep_time{};
    std::string current_guard_id;
    for (const auto &l : reports) {
        if (is_beginning_shift(l, guard_begins_regex)) {
            current_guard_id = get_id(l, guard_id_regex);
        } else if (is_falling_asleep(l, guard_asleep_regex)) {
            sleep_time = get_date_time(l, date_regex);
        } else if (is_awake(l, guard_awake_regex)) {
            const auto current_time = get_date_time(l, date_regex);
            guard_sleep_map[current_guard_id] += (std::difftime(current_time, sleep_time) / 60);
        }
    }

    const auto guard_with_most_sleep =
            std::max_element(guard_sleep_map.begin(), guard_sleep_map.end(), compare_guard_sleep)->first;

    std::map<int, int> most_frequent_time;

    int current_minute = 0;
    for (const auto &line : reports) {
        if (is_beginning_shift(line, guard_begins_regex)) {
            current_guard_id = get_id(line, guard_id_regex);
        } else if (current_guard_id == guard_with_most_sleep && is_falling_asleep(line, guard_asleep_regex)) {
            current_minute = get_minute(line, date_regex);
            ++most_frequent_time[current_minute];
        } else if (is_awake(line, guard_awake_regex) && current_guard_id == guard_with_most_sleep) {
            auto time_slept = (get_minute(line, date_regex) - 1) - current_minute;
            for (auto i = 0; i != time_slept; ++i) {
                ++most_frequent_time[++current_minute];
            }
        }
    }

    const auto most_slept_time =
            std::max_element(most_frequent_time.begin(), most_frequent_time.end(), compare_sleep_time)->first;

    return std::stoi(guard_with_most_sleep.substr(1)) * most_slept_time;
}

int day4::find_most_frequently_asleep_guard(const std::set<std::string> reports) {
    std::unordered_map<std::string, std::unordered_map<int, int>> map;

    const std::regex guard_awake_regex{R"((\bwakes\b))"};
    const std::regex guard_begins_regex{R"((\bbegins\b))"};
    const std::regex guard_asleep_regex{R"((\bfalls\b))"};
    const std::regex date_regex{R"(\[(.+)\])"};
    const std::regex guard_id_regex{R"((\#(\d+)))"};

    std::string current_guard_id;
    int current_minute = 0;
    for (const auto &line : reports) {
        if (is_beginning_shift(line, guard_begins_regex)) {
            current_guard_id = get_id(line, guard_id_regex);
        } else if (is_falling_asleep(line, guard_asleep_regex)) {
            current_minute = get_minute(line, date_regex);
            ++map[current_guard_id][current_minute];
        } else if (is_awake(line, guard_awake_regex)) {
            auto time_slept = (get_minute(line, date_regex) - 1) - current_minute;
            for (auto i = 0; i != time_slept; ++i) {
                ++map[current_guard_id][++current_minute];
            }
        }
    }

    std::pair<std::string, int> guard_info{"#000", 0};
    int max_count = 0;

    for (const auto &item: map) {
        const auto most = std::max_element(item.second.begin(), item.second.end(), compare_sleep_time);
        if (most->second > max_count) {
            max_count = most->second;
            guard_info.second = most->first;
            guard_info.first = item.first;
        }
    }

    return std::stoi(guard_info.first.substr(1)) * guard_info.second;
}
