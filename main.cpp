//
// Created by Patrick on 12/1/2018.
//

#include <iostream>
#include "day1.h"

int main() {

    {
        auto inputs = day1::get_inputs();
        auto sum_of_inputs = day1::sum_of_frequencies(inputs);
        auto frequency = day1::get_first_duplicate_frequency(inputs);
        std::cout << "Day 1: \n" << "Sum Of Frequencies: " << sum_of_inputs << "\n"
                  << "First Duplicate Frequency: "
                  << frequency << "\n" << std::endl;
    }

}