//
// Author           : skannan
// Timestamp        : 8/16/21, 7:14 PM
// Description      : A Stack ADT
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_STACK_H
#define ALGORITHMS_AND_DATA_STRUCTURES_STACK_H
#include "LinkedList.h"

namespace ADT {
template <typename T> class Stack : private ADT::LinkedList<T> {
    public:
        /* Constructors */
        Stack() = default;
        explicit Stack(const T &item) : LinkedList<T>(item) {}

        /* Stack operations */
        void push(const T &item) { this->push_front(item); }
        T pop() {
            check("pop on empty stack.");
            auto ret = this->front();
            this->erase_front();
            return ret;
        }
        T &top() const { check("top on empty stack") ; return this->front(); }

        typename LinkedList<T>::size_type size() const override { return this->sz;}
        bool empty() const override {return this->sz == 0;}

    private:
        void check(const std::string &msg) const {
            if(this->empty())
                throw(std::runtime_error(msg));
        }
};
}

#endif //ALGORITHMS_AND_DATA_STRUCTURES_STACK_H
