// valid.cpp - define the function for computing the validity of magic squares
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

#include <numeric>
#include <iterator>
#include <vector>

bool valid(std::vector<uint>& perm, uint& target) {
    // Total all values in direction and find if equal to target

    // Check rows
    for(uint i = 0; i < FLAGS_width; ++i) {
        // Get sum of all values between (width * i) and (width * (i + 1))
        if(std::accumulate(perm.begin() + (FLAGS_width * i), perm.begin() +
        (FLAGS_width * (i + 1)), 0) != target) {
            return false;
        }
    }

    uint sum;

    // Check columns
    for(uint i = 0; i < FLAGS_width; ++i) {
        // Get iterator to initial column
        auto iter = perm.begin() + i;

        // Reset sum value
        sum = *iter;

        // Loop through each row
        for(uint j = 0; j < FLAGS_width - 1; ++j) {
            std::advance(iter, FLAGS_width);
            sum += *iter;
        }

        // Check value
        if(sum != target) {
            return false;
        }
    }

    // Check diagonals

    // LR Diagonal
    sum = 0;
    auto iter = perm.begin();

    for(uint i = 0; i < FLAGS_width; ++i) {
        sum += *iter;
        iter += FLAGS_width + 1;
    }

    // Check value
    if(sum != target) {
        return false;
    }

    // RL Diagonal
    sum = 0;
    iter = perm.begin() + (FLAGS_width - 1);

    for(uint i = 0; i < FLAGS_width; ++i) {
        sum += *iter;
        iter += FLAGS_width - 1;
    }

    // Check value
    if(sum != target) {
        return false;
    }

    return true;
}
