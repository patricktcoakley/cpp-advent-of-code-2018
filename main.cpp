//
// Created by Patrick on 12/1/2018.
//

#include <thread>
#include <chrono>
#include <iostream>
#include "solve/solve.h"

int main() {
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    std::thread day1(solve_day_1);
    std::thread day2(solve_day_2);
    std::thread day3(solve_day_3);
    std::thread day4(solve_day_4);
    std::thread day5(solve_day_5);
    std::thread day6(solve_day_6);

    day1.join();
    day2.join();
    day3.join();
    day4.join();
    day5.join();
    day6.join();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::high_resolution_clock::now() - start).count();
    std::cout << duration << "ms" << std::endl;

}