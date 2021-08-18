//
// Author           : skannan
// Timestamp        : 8/13/21, 4:00 PM
// Description      : Contains two methods to perform a binary search on any c++ standard library container
//

#ifndef __GENERIC_ALGORITHMS__H
#define __GENERIC_ALGORITHMS__H

#include <algorithm>

namespace GenericAlgorithms {

    /* Binary search algorithms
     * Requires container type to be any of the standard library containers - vector, list, array, map, etc.
     * Returns the index where the sought element is found, -1 if not found.
    */
    template <typename X, typename Y>
    int binary_search_naive(const X &set, const Y &sought){
        auto beg = set.begin(), end = set.end();
        auto mid = beg + (end - beg) / 2;
        while (mid != end) {
            if (*mid == sought) {
                return static_cast<int>(std::distance(set.begin(), mid));
            }
            if (*mid < sought)
                beg = mid + 1;
            else
                end = mid;
            mid = beg + (end - beg) / 2;
        }

        return -1;
    }

    template <typename X, typename Y>
    int binary_search_recursion(const X &beg, const X &end, const Y &sought){
        static auto set_begin = beg;
        if(beg == end)
            return -1;
        auto mid = beg + (end - beg) / 2;
        if(*mid < sought)
            return binary_search_recursion(mid + 1, end, sought);
        else if(sought < *mid)
            return binary_search_recursion(beg, mid, sought);
        return static_cast<int>(std::distance(set_begin, mid));
    }
}
#endif // __GENERIC_ALGORITHMS__H


