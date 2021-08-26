#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

typedef unsigned long long Floor_N;

Floor_N egg_dropping_variant_1(const std::vector<bool> &floors);
Floor_N egg_dropping_variant_2(const std::vector<bool> &floors);
Floor_N egg_dropping_variant_3(const std::vector<bool> &floors);
Floor_N egg_dropping_variant_4(const std::vector<bool> &floors);

int main(int argc, char **argv){
    /* k = 50 , T = 13 , 1 egg */
    Floor_N k = 50, T = 29;
    std::vector<bool> vec;
    std::fill_n(std::back_inserter(vec), T-1, false);
    std::fill_n(std::back_inserter(vec),k - T + 1, true );
    std::cout << "actual : " << egg_dropping_variant_4(vec) << " ; expected : " << T  << std::endl;
    return 0;
}