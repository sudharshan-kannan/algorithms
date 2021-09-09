//
// Author           : skannan
// Timestamp        : 9/4/21, 2:32 PM
// Description      : Concrete class that implements the UnionFind algorithm using 'quick-find' method
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_QUICKFIND_H
#define ALGORITHMS_AND_DATA_STRUCTURES_QUICKFIND_H

#include "UnionFind.h"

namespace DynamicConnectivity{

    class QuickFind : public UnionFind{
    public:
        using UnionFind::Node;
        explicit QuickFind(Node n_sites):UnionFind(n_sites){}
        void link(Node p, Node q) override {
            /* Maintain invariant that two nodes are connected if they have the same IDs (transitivity) */
            auto pID = find(p), qID = find(q);
            if(pID == qID) return;
            for(auto &s : this->sites)
                if(s == pID) s = qID;
            --this->n_components;
        }
        Node find(Node p) const override{
            /* Simply return the component ID of the node */
            return this->sites[p];
        }
    };
} // namespace DynamicConnectivity
#endif //ALGORITHMS_AND_DATA_STRUCTURES_QUICKFIND_H
