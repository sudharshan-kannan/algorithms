//
// Author           : skannan
// Timestamp        : 9/4/21, 3:23 PM
// Description      : Concrete class that implements the Union-Find alogorithm using an economical quick union method
//
#include "UnionFind.h"
#include <vector>

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_WEIGHTEDQUICKUNION_H
#define ALGORITHMS_AND_DATA_STRUCTURES_WEIGHTEDQUICKUNION_H
namespace DynamicConnectivity {
    class WeightedQuickUnion : public UnionFind {
    public:
        using UnionFind::Node;
        explicit WeightedQuickUnion(Node n_sites):UnionFind(n_sites), sz(n_sites,0){}
        void link(Node p, Node q) override {
            /* Connect the root of p and q */
            Node pRoot = this->find(p), qRoot = this->find(q);

            if(pRoot == qRoot) return;

            /* Always connect smaller size tree to larger one to limit tree's growth */
            if(sz[pRoot] < sz[qRoot])   {this->sites[pRoot] = qRoot; sz[qRoot] += sz[pRoot];}
            else                        {this->sites[qRoot] = pRoot; sz[pRoot] += sz[qRoot];}

            --this->n_components;
        }
        Node find(Node p) const override{
            /* Find the root node of p */
            while(this->sites[p] != p)
                p = this->sites[p];

            return p;
        }
    private :
        std::vector<Node> sz;
    };
} // namespace DynamicConnectivity
#endif //ALGORITHMS_AND_DATA_STRUCTURES_WEIGHTEDQUICKUNION_H
