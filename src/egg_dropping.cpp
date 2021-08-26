//
// Author           : skannan
// Timestamp        : 8/25/21, 9:11 PM
// Compile command  : g++ -Wall -o exec egg_dropping.cpp -I ~/CLionProjects/cpp-primer/include
// Description      : Find floor T in least egg drops where it doesn't break
//

// Using bitset largely simplifies the implementation
// Floor T is identified by the first 'true' element in a vector of bool
#include <vector>
#include <iostream>
#include <cmath>
#include "../include/generic_algorithms.h"

typedef unsigned long long Floor_N;

/* Variant 1 :
 * Goal             : Find floor T in least drops with total floors k and 1 egg.
 * Algorithm        : Sequential search (drop from each floor from bottom and stop where the egg breaks)
 * Order of growth  : Linear ( O(N) )
 */

Floor_N egg_dropping_variant_1(const std::vector<bool> &floors){
    for(auto d = 0; d != floors.size(); ++d) {
        if (floors[d])
            return d + 1;
    }
    return 0;
}


/* Variant 2 :
 * Goal             : Find floor T in least drops with total floors k and infinite eggs.
 * Algorithm        : Binary search for T
 * Order of growth  : Logrithmic ( O(log N) )
 */

Floor_N egg_dropping_variant_2(const std::vector<bool> &floors){
    // Mantain invariant : egg breaks on high and not on low
    auto low = floors.begin(), high = floors.end();
    auto mid = low + (high - low) / 2;
    while(low+1 != high) {
        if(*mid == 1) // egg breaks in mid
            high = mid;
        else if(*mid == 0) // egg did not break
            low = mid + 1;
        mid = low + (high - low) / 2;
    }
    return static_cast<Floor_N>(std::distance(floors.begin(), mid)) + 1;
}


/* Variant 3 :
 * Goal             : Find floor T in least drops with total floors k and infinite eggs.
 * Algorithm        : Repeated doubling with Binary Search for T
 * Order of growth  : Logrithmic ( O(log N) )
 */

Floor_N egg_dropping_variant_3(const std::vector<bool> &floors){
    Floor_N i = 1;
    for(; i != floors.size(); i*=2)
        if(floors[i-1])
            break;
        /* Do binary search from i/2 to i */
    std::cout << "do binary search between : " << i / 2 << " and " << i << std::endl;
    auto low = floors.begin() + (i / 2), high = floors.begin() + i;
    auto mid = low + (high - low) / 2;

    while(low+1 != high){
        if(*mid == 1)
            high = mid;
        else if(*mid == 0)
            low = mid + 1;
        mid = low + (high - low) / 2;
    }
    return static_cast<Floor_N>(std::distance(floors.begin(), mid)) + 1;
}

/* Variant 4 :
 * Goal             : Find floor T in least drops with total floors k and 2 eggs.
 * Algorithm        : Gridding with Binary Search for T
 * Order of growth  : Logrithmic ( O(sqrt(N)log N) )
 */

Floor_N egg_dropping_variant_4(const std::vector<bool> &floors) {
    Floor_N i = 0;
    auto n = floors.size();
    auto interval = std::round(sqrt(n));
    for(;i != n; ++i) {
        auto idx = static_cast<std::vector<bool>::size_type>(i * interval);
        if(floors[idx])
            break;
    }

    /* Do sequential search with the remaining egg from i root n - root n to i root n */
    Floor_N low = (i * interval) - interval;
    Floor_N high = (i * interval) + 1;
    for(auto x = low; x != high; ++x)
        if(floors[x])
            return x + 1;
    return 0;
}