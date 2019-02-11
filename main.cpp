//
// Created by Patrick on 12/1/2018.
//

#include <thread>
#include <chrono>
#include <iostream>
#include "solve/solve.h"

int main() {
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
//
//    std::thread day1(solve_day_1);
//    std::thread day2(solve_day_2);
//    std::thread day3(solve_day_3);
    std::thread day5 (solve_day_5);

//    day1.join();
//    day2.join();
//    day3.join();
    day5.join();

    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    std::cout << duration << "ms " << std::endl;

}