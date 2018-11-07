// valid.hpp - define functions used for magic square validation
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

#include <vector>

// Header guard
#ifndef VALID_HPP
#define VALID_HPP

// Valid function
// Takes an std::vector and returns a bool specifying whether or not it is a
// magic square. Calculates side width based on vector size.
bool valid(std::vector<uint>& perm, uint& target);

#endif
