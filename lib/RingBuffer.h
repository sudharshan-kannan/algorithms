//
// Author           : skannan
// Timestamp        : 8/17/21, 11:04 PM
// Description      : A Ring Buffer ADT
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_RINGBUFFER_H
#define ALGORITHMS_AND_DATA_STRUCTURES_RINGBUFFER_H

#include "Queue.h"
#include <iostream>

namespace ADT {
template <typename T> class RingBuffer : public ADT::Queue<T> {
    public:
        /* Constructors */
        RingBuffer() = default;
        explicit RingBuffer(const T &item) : ADT::Queue<T>(item){}

        std::shared_ptr<typename ADT::LinkedList<T>::Node> get_first_node() const{
            return this->first;
        }
        std::shared_ptr<typename ADT::LinkedList<T>::Node> get_last_node(){
            return this->last;
        }

        void enqueue(const T &item) override {
            auto old_last = this->last;
            this->last = std::make_shared<typename ADT::LinkedList<T>::Node>(item, this->first);
            old_last->next = this->last;
            ++this->sz;
        }

        T dequeue() override {
            check("dequeue on empty ring buffer");
            auto ret = this->front();
            this->erase_front();
            this->last->next = this->first;
            return ret;
        }

        void erase(std::shared_ptr<typename ADT::LinkedList<T>::Node> node){
            check("erase on empty ring buffer");
            if(node == this->first)
                this->dequeue();
            else if(node == this->last){
                this->erase(this->size() - 1);
            }
            else {
                auto it = this->first;
                for (; it->next != node; it = it->next);
                it->next = node->next;
                --this->sz;
            }
        }

         T erase(typename ADT::LinkedList<T>::size_type pos) override{
            check("erase on empty ring buffer");
            pos %= this->sz;
            auto ret = T();
            if(pos == 0) {
                /* Special case where we want to erase first element indirectly */
                ret = this->front();
                this->dequeue();
            }
            else if (pos == this->size() - 1){
                /* Special case where we want to erase the last element indirectly */
                ret = this->back();
                auto it = this->first;
                for(;it->next != this->last ; it = it->next);
                it->next = this->first;
                this->last = it;
                --this->sz;
            }
            else{
                /* Erase an element with index = pos */
                ret = ADT::LinkedList<T>::erase(pos);
            }
            return ret;
        }
    private:
        void check(const std::string msg) const {
            if(this->empty())
                throw(std::runtime_error(msg));
        }
 };
}

#endif //ALGORITHMS_AND_DATA_STRUCTURES_RINGBUFFER_H
