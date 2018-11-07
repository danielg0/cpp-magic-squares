// main.cpp - Define main function
// Copyright (C) 2018  Daniel G.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "main.hpp"
#include "valid.hpp"

#include <gflags/gflags.h>

#include <algorithm>
#include <iostream>
#include <numeric>

// Define command line flags
DEFINE_uint64(width, 3, "The side length of the magic squares generated");

// Main function
// Outputs all magic squares of side length WIDTH
int main(int argc, char *argv[]) {
    // Get gflags to parse the command line flags
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    // Define the grid size (width * width)
    uint size = FLAGS_width * FLAGS_width;

    // Find the magic number (the target number all the rows should total to)
    uint target = FLAGS_width * (((FLAGS_width * FLAGS_width) + 1) / 2);

    // Create a vector to hold the current permutation and fill it with values
    std::vector<uint> perm(size);
    std::iota(perm.begin(), perm.end(), 1);

    // Loop through every permutation
    do {
        // Check the current permutation
        if(valid(perm, target)) {
            // Output the permutation
            for(uint value : perm) {
                std::cout << value << ",";
            }
            std::cout << "\n";
        }
    } while (std::next_permutation(perm.begin(), perm.end()));

    return 0;
}
