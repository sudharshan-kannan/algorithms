//
// Author           : skannan
// Timestamp        : 9/4/21, 3:02 PM
// Description      : Concrete class that implements the Union-Find alogorithm using forest of trees
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_QUICKUNION_H
#define ALGORITHMS_AND_DATA_STRUCTURES_QUICKUNION_H

#include "UnionFind.h"

namespace DynamicConnectivity {
    class QuickUnion : public UnionFind {
    public:
        using UnionFind::Node;
        explicit QuickUnion(Node n_sites):UnionFind(n_sites){}
        void link(Node p, Node q) override {
            /* Connect the root of p and q */
            Node pRoot = this->find(p), qRoot = this->find(q);

            if(pRoot == qRoot) return;

            this->sites[pRoot] = qRoot;

            --this->n_components;
        }
        Node find(Node p) const override{
            /* Find the root node of p */
            while(this->sites[p] != p)
                p = this->sites[p];

            return p;
        }
    };
} // namespace DynamicConnectivity
#endif //ALGORITHMS_AND_DATA_STRUCTURES_QUICKUNION_H
