//
// Created by Patrick on 2/8/2019.
//

#include <iostream>
#include "../day1/day1.h"
#include "../day2/day2.h"
#include "../day3/day3.h"
#include "../day4/day4.h"
#include "../day5/day5.h"

void solve_day_1() {
    const auto inputs = day1::get_inputs();
    const auto sum_of_inputs = day1::sum_of_frequencies(inputs);
    const auto frequency = day1::get_first_duplicate_frequency(inputs);
    std::cout << "Day 1: \n" << "Sum Of Frequencies: " << sum_of_inputs << "\n" << "First Duplicate Frequency: "
              << frequency << "\n" << std::endl;
}


void solve_day_2() {
    const auto inputs = day2::get_inputs();
    const auto checksum = day2::checksum(inputs);
    const auto common_letters = day2::find_common_letters(inputs);
    std::cout << "Day 2: \n" << "Checksum: " << checksum << "\n" << "Common Letters: " << common_letters << "\n"
              << std::endl;
}

void solve_day_3() {
    const auto inputs = day3::get_inputs();
    const auto fabrics = day3::get_fabric_locations(inputs);
    const auto overlapping_fabrics = day3::find_overlapping_fabrics(fabrics);
    const auto non_overlapping_fabric = day3::find_non_overlapping_fabric(fabrics);

    std::cout << "Day 3: \n" << "Overlapping Fabrics: " << overlapping_fabrics << "\n" << "Non-Overlapping Fiber: "
              << non_overlapping_fabric << "\n" << std::endl;
}

void solve_day_4() {
    const auto inputs = day4::get_inputs();
    day4::find_guard_who_slept_most(inputs);
}

void solve_day_5() {
    const auto inputs = day5::get_inputs();
    const auto size = day5::get_size_of_polymer(inputs);
    const auto shortest = day5::find_size_of_shortest_polymer(inputs);

    std::cout << "Day 5: \n" << "Size Of Polymers: " << size << "\n" << "Shortest Polymers: " << shortest << "\n"
              << std::endl;
}