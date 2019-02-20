//
// Created by Patrick on 12/4/2018.
//

#include <fstream>
#include <regex>
#include <unordered_map>
#include "day4.h"

std::set<std::string> day4::get_inputs() {
    std::set<std::string> inputs;
    std::fstream in;
    in.open("inputs/day4.txt");

    for (std::string line; std::getline(in, line);) inputs.insert(line);

    return inputs;
}

constexpr auto compare_guard_sleep(const std::pair<std::string, double> &kvp1, const std::pair<std::string, double> &kvp2) {
    return kvp1.second < kvp2.second;
}

constexpr auto compare_sleep_time (const std::pair<int, int> &kvp1, const std::pair<int, int> &kvp2) {
    return kvp1.second == kvp2.second ? kvp1.first < kvp2.first : kvp1.second < kvp2.second;
}

bool is_beginning (const std::string &s, const std::regex &guard_begins_regex) {
    return std::regex_search(s, guard_begins_regex);
}

bool is_awake(const std::string &s, const std::regex &guard_awake_regex) {
    return std::regex_search(s, guard_awake_regex);
}

bool is_asleep(const std::string &s, const std::regex &guard_asleep_regex) {
    return std::regex_search(s, guard_asleep_regex);
}

const std::string get_id(const std::string &s, const std::regex &guard_id_regex) {
    std::smatch matches;
    std::regex_search(s, matches, guard_id_regex);
    return matches[0];
}

std::time_t get_date_time(const std::string &s, const std::regex &date_regex) {
    std::tm date{};
    std::smatch matches;
    std::regex_search(s, matches, date_regex);
    const auto format = "[%Y-%m-%d %H:%M]";
    strptime(matches[0].str().c_str(), format, &date);
    date.tm_year += 500; // year is pre-epoch UNIX time and therefore should be increased equally
    return mktime(&date);
}

std::time_t get_minutes(const std::string &s, const std::regex &date_regex) {
    std::tm date{};
    std::smatch matches;
    std::regex_search(s, matches, date_regex);
    const auto format = "[%Y-%m-%d %H:%M]";
    strptime(matches[0].str().c_str(), format, &date);
    return date.tm_min;
}


int day4::find_guard_who_slept_most(const std::set<std::string> &reports) {
    std::unordered_map<std::string, double> guard_sleep_map;

    const std::regex guard_awake_regex{R"((\bwakes\b))"};
    const std::regex guard_begins_regex{R"((\bbegins\b))"};
    const std::regex guard_asleep_regex{R"((\bfalls\b))"};
    const std::regex date_regex{R"(\[(.+)\])"};
    const std::regex guard_id_regex{R"((\#(\d+)))"};

    std::time_t sleep_time{};
    std::string current_guard_id;
    for (const auto &l : reports) {
        if (is_beginning(l, guard_begins_regex)) {
            current_guard_id = get_id(l, guard_id_regex);
        } else if (is_asleep(l, guard_asleep_regex)) {
            sleep_time = get_date_time(l, date_regex);
        } else if (is_awake(l, guard_awake_regex)) {
            auto current_time = get_date_time(l, date_regex);
            guard_sleep_map[current_guard_id] += std::difftime(current_time, sleep_time) / 60;
        }
    }

    const auto guard_with_most_sleep =
            std::max_element(guard_sleep_map.begin(), guard_sleep_map.end(), compare_guard_sleep);

    std::unordered_map<int, int> most_frequent_time;

    for (const auto &line : reports) {
        if (is_beginning(line, guard_begins_regex)) {
            current_guard_id = get_id(line, guard_id_regex);
        } else if (current_guard_id == guard_with_most_sleep->first && is_asleep(line, guard_asleep_regex)) {
            most_frequent_time[get_minutes(line, date_regex)] += 1;
        }
    }

    const auto most_slept_time =
            std::max_element(most_frequent_time.begin(), most_frequent_time.end(), compare_sleep_time);

    return (most_slept_time->first) * std::stoi(guard_with_most_sleep->first.substr(1));
}
