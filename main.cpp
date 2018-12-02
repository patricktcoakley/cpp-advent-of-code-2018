//
// Created by Patrick on 12/1/2018.
//

#include <iostream>
#include "day1.h"
#include "day2.h"

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

}