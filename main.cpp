//
// Created by Patrick on 12/1/2018.
//

#include <iostream>
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"

int main() {

    {
        auto inputs = day1::get_inputs();
        auto sum_of_inputs = day1::sum_of_frequencies(inputs);
        auto frequency = day1::get_first_duplicate_frequency(inputs);
        std::cout << "Day 1: \n" << "Sum Of Frequencies: " << sum_of_inputs << "\n" << "First Duplicate Frequency: "
                  << frequency << "\n" << std::endl;
    }

    {
        auto inputs = day2::get_inputs();
        auto checksum = day2::checksum(inputs);
        auto common_letters = day2::find_common_letters(inputs);
        std::cout << "Day 2: \n" << "Checksum: " << checksum << "\n" << "Common Letters: " << common_letters << "\n"
                  << std::endl;
    }

    {
        auto inputs = day3::get_inputs();
        auto fabrics = day3::get_fabric_locations(inputs);
        auto overlapping_fabrics = day3::find_overlapping_fabrics(fabrics);
        auto non_overlapping_fabric = day3::find_non_overlapping_fabric(fabrics);

        std::cout << "Day 3: \n" << "Overlapping Fabrics: " << overlapping_fabrics << "\n" << "Non-Overlapping Fiber: "
                  << non_overlapping_fabric << "\n" << std::endl;
    }

    {
        auto inputs = day5::get_inputs();
        auto size = day5::get_size_of_polymer(inputs);
        auto shortest = day5::find_size_of_shortest_polymer(inputs);
        std::cout << "Day 5: \n" << "Size Of Polymers: " << size << "\n" << "Shortest Polymers: " << shortest << "\n"
                  << std::endl;

    }
}