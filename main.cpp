#include "include/driver.h"
#include <iostream>
typedef unsigned long long Node;
int main(int argc, char **argv){
    auto n_nodes = static_cast<Node>(std::stoi(argv[3]));
    std::cout << "Implementing using Quick Find algorithm...";
    performDynamicConnectivity(argv[1], argv[2], n_nodes,UnionFindAlgorithm::QUICK_FIND);
    std::cout << " Done. " << std::endl;
    return EXIT_SUCCESS;
}
