//
// Author           : skannan
// Timestamp        : 9/2/21, 12:25 AM
// Description      : An abstract class that contains APIs to solve the classic dynamic connectivity problem
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_DYNAMICCONNECTIVITY_H
#define ALGORITHMS_AND_DATA_STRUCTURES_DYNAMICCONNECTIVITY_H

#include <vector>
#include <iostream>

namespace DynamicConnectivity {

    class UnionFind {
    public:
        using Node = unsigned long long;
        explicit UnionFind(Node n_sites) : n_components(n_sites) {
            /* Each site belongs to distinct component on start up */
            for (auto i = 0; i != n_sites; ++i)
                sites.push_back(i);
        }

        /* Union API - add connection between p and q */
        virtual void link(Node p, Node q) = 0;

        /* Find API - find the component identifier for the node */
        virtual Node find(Node p) const = 0;

        /* Check if two nodes are connected through equivalence class */
        bool connected(Node p, Node q) const { return find(p) == find(q); }

        /* Count of number of components currently present in the area */
        Node count() const { return n_components; }

    protected:
        std::vector<Node> sites;
        Node n_components;
    };
} // namespace DynamicConnectivity
#endif //ALGORITHMS_AND_DATA_STRUCTURES_DYNAMICCONNECTIVITY_H
