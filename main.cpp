//
// Created by Patrick on 12/1/2018.
//

#include <iostream>
#include <thread>
#include "solve/solve.h"

int main() {

//    std::thread day1(solve_day_1);
//    std::thread day2(solve_day_2);
//    std::thread day3(solve_day_3);
    std::thread day5 (solve_day_5);
//
//    day1.join();
//    day2.join();
//    day3.join();
    day5.join();

}