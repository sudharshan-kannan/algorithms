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
#include "generic_algorithms.h"
#include "../lib/LinkedList.h"
#include "../lib/Stack.h"


/* Whitelisting
 * Input  : whitelist file and file containing search elements
 * Output : Entries not contained within the whitelit file
*/
void whitelist_ints(const std::string &whitelist_file, const std::string &infile, const std::string &outfile);


/* Dynamic Connectivity
 * Input    : File containing pairs of connections, number of nodes or sites in the area, and the type of algorithm to use
 * Output   : Count of number of distinct components
*/
enum class UnionFindAlgorithm {QUICK_FIND, QUICK_UNION, WEIGHTED_QUICK_UNION, WEIGHTED_QUICK_UNION_PATH_COMPRESSION};
void performDynamicConnectivity(const std::string &infile, const std::string &outfile, unsigned long long N, UnionFindAlgorithm algorithm);

#endif //ALGORITHMS_AND_DATA_STRUCTURES_DRIVER_H
