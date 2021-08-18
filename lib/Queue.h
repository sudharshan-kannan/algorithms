//
// Author           : skannan
// Timestamp        : 8/17/21, 3:01 PM
// Description      : A Queue ADT
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_QUEUE_H
#define ALGORITHMS_AND_DATA_STRUCTURES_QUEUE_H
#include "LinkedList.h"

namespace ADT {
    template <typename T> class Queue : protected ADT::LinkedList<T> {
    public:
        /* Constructors */
        Queue() = default;
        explicit Queue(const T &item) : LinkedList<T>(item), last(this->first) {}

        /* Queue operations */
        virtual void enqueue(const T &item) {
            auto old_last = last;
            last = std::make_shared<typename ADT::LinkedList<T>::Node>(item, nullptr);
            old_last->next = last;
            ++this->sz;
        }
        virtual T dequeue() {
            check("dequeue on empty queue.");
            auto ret = this->front();
            this->erase_front();
            return ret;
        }
        T &front() const { check("front on empty queue") ; return ADT::LinkedList<T>::front(); }
        T &back() const {check("back on empty queue"); return last->val;}

        virtual typename LinkedList<T>::size_type size() const override { return this->sz;}
        virtual bool empty() const override {return this->sz == 0;}

    protected:
        std::shared_ptr<typename ADT::LinkedList<T>::Node> last;
        void check(const std::string &msg) const {
            if(this->empty())
                throw(std::runtime_error(msg));
        }
    };
}

#endif //ALGORITHMS_AND_DATA_STRUCTURES_QUEUE_H
