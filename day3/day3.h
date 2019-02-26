//
// Created by Patrick on 12/3/2018.
//

#ifndef AOC2018_DAY3_H
#define AOC2018_DAY3_H

#endif //AOC2018_DAY3_H

#include <vector>
#include <string>

namespace day3 {

    const std::vector<std::string> get_inputs();

    struct fabric { int id, x, y, width, height; };

    const std::vector<fabric> get_fabric_locations(const std::vector<std::string> &fabric_locations);

    int find_overlapping_fabrics(const std::vector<fabric> &fabrics);

    int find_non_overlapping_fabric(const std::vector<fabric> &fabrics);
}