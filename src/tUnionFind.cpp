//
// Author           : skannan
// Timestamp        : 9/6/21, 2:14 PM
// Compile command  : g++ -Wall -o exec tUnionFind.cpp -I ~/CLionProjects/cpp-primer/include
// Description      : A test to demonstrate the dynamic connectivity problem using UnionFind algorithm
//

#include "../include/driver.h"
#include "../include/UnionFind.h"
#include "../include/QuickFind.h"
#include "../include/QuickUnion.h"
#include "../include/WeightedQuickUnion.h"
#include <iostream>
#include <sstream>
#include <string>

void performDynamicConnectivity(const std::string &infile, const std::string &outfile, unsigned long long N, UnionFindAlgorithm algorithm){
    using namespace DynamicConnectivity;
    UnionFind::Node n_components = N;
    std::shared_ptr<UnionFind> uf;
    switch(algorithm) {
        case UnionFindAlgorithm::QUICK_FIND:
             uf = std::make_shared<QuickFind>(N);
            break;
        case UnionFindAlgorithm::QUICK_UNION:
            uf = std::make_shared<QuickUnion>(N);
            break;
        case UnionFindAlgorithm::WEIGHTED_QUICK_UNION:
            uf = std::make_shared<WeightedQuickUnion>(N);
            break;
        default:
            /* TODO : Implement WQU with path compression */
            break;
    }
    std::ifstream is(infile);
    if(!is.is_open()) { std::cerr << "Error opening link file."; return;}
    std::ofstream os(outfile, std::ofstream::app);
    if(!os.is_open()) { std::cerr << "Error opening output file"; return;}
    std::string linkPair;
    // skip first line that contains the number of nodes
    getline(is,linkPair);
    while(getline(is,linkPair)) {
        std::istringstream pairStr(linkPair);
        std::string pStr, qStr;
        pairStr >> pStr >> qStr;
        auto p = static_cast<UnionFind::Node>(stoi(pStr));
        auto q = static_cast<UnionFind::Node>(stoi(qStr));
        if(!uf->connected(p, q)) {uf->link(p, q); os << p << " " << q << "\n"; }
    }
    os << uf->count() << " components.\n";
}