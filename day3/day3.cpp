//
// Created by Patrick on 12/3/2018.
//

#include <fstream>
#include "day3.h"

const std::vector<std::string> day3::get_inputs() {
    std::vector<std::string> inputs;
    std::fstream in;
    in.open("inputs/day3.txt");

    for (std::string line; std::getline(in, line);)
        inputs.push_back(line);

    return inputs;
}

const std::vector<day3::fabric> day3::get_fabric_locations(const std::vector<std::string> &fabric_locations) {
    std::vector<day3::fabric> fabrics;
    for (const auto &fabric_location: fabric_locations) {
        int id, x, y, width, height;
        id = std::stoi(fabric_location.substr(1, fabric_location.find('@')));
        x = std::stoi(fabric_location.substr(fabric_location.find('@') + 2,
                                             fabric_location.find(',') - fabric_location.find('@') - 2));
        y = std::stoi(fabric_location.substr(fabric_location.find(',') + 1,
                                             fabric_location.find(':') - fabric_location.find(',') - 1));
        width = std::stoi(fabric_location.substr(fabric_location.find(": ") + 2,
                                                 fabric_location.find('x') - fabric_location.find(": ") - 2));
        height = std::stoi(fabric_location.substr(fabric_location.find('x') + 1));

        fabric f{id, x, y, width, height};

        fabrics.push_back(f);
    }

    return fabrics;
}

int day3::find_overlapping_fabrics(const std::vector<day3::fabric> &fabrics) {
    int count = 0;

    std::vector<std::vector<int>> vec(1000, std::vector<int>(1000));

    for (const auto &fabric: fabrics) {
        for (int x = fabric.x; x < fabric.x + fabric.width; ++x) {
            for (int y = fabric.y; y < fabric.y + fabric.height; ++y) {

                if (vec[x][y] == 0) vec[x][y] = fabric.id;

                else if (vec[x][y] > 0) {
                    ++count;
                    vec[x][y] = -1;
                }
            }
        }
    }

    return count;
}

int day3::find_non_overlapping_fabric(const std::vector<day3::fabric> &fabrics) {
    int no_overlap_id = -1;

    std::vector<std::vector<int>> vec(1000, std::vector<int>(1000));

    for (const auto &fabric: fabrics) {
        for (int x = fabric.x; x < fabric.x + fabric.width; ++x) {
            for (int y = fabric.y; y < fabric.y + fabric.height; ++y) {

                if (vec[x][y] == 0) vec[x][y] = fabric.id;

                else if (vec[x][y] > 0) {
                    vec[x][y] = -1;
                }
            }
        }
    }

    for (const auto &fabric: fabrics) {
        bool has_no_overlap = true;
        for (int x = fabric.x; x < fabric.x + fabric.width; ++x) {
            for (int y = fabric.y; y < fabric.y + fabric.height; ++y) {
                if (vec[x][y] < 1) has_no_overlap = false;
            }
        }
        if (has_no_overlap) no_overlap_id = fabric.id;
    }
    return no_overlap_id;
}