//
// Author           : skannan
// Timestamp        : 8/14/21, 10:19 PM
// Description      : Universal header file that contains most needed headers and test methods declarations
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_DRIVER_H
#define ALGORITHMS_AND_DATA_STRUCTURES_DRIVER_H
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include "../include/generic_algorithms.h"
#include "../lib/LinkedList.h"
#include "../lib/Stack.h"


/* Input : whitelist file and file containing search elements */
void whitelist_ints(const std::string &whitelist_file, const std::string &infile, const std::string &outfile);

#endif //ALGORITHMS_AND_DATA_STRUCTURES_DRIVER_H
