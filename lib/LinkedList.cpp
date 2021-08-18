//
// Author           : skannan
// Timestamp        : 8/16/21, 2:20 PM
// Compile command  : g++ -Wall -o exec LinkedList.cpp -I ~/CLionProjects/cpp-primer/include
// Description      : Implementation of the generic LinkedList ADT
//

#include "LinkedList.h"
#include <stdexcept>

template <typename T>
void ADT::LinkedList<T>::push_front(const T &item){
    auto old_first = first;
    first = std::make_shared<Node>(item, old_first);
    ++sz;
}

template <typename T>
void ADT::LinkedList<T>::push_back(const T &item){
    // 0 1 2 3 4 5 6 7 8
    auto it = first;
    for(;it->next != nullptr; it = it->next);
    auto last = std::make_shared<Node>(item, nullptr);
    it->next = last;
    ++sz;
}

template <typename T>
void ADT::LinkedList<T>::insert(const T &item, size_type pos){
    // 0 1 2 3 4 5 6 7 8 9
    check(pos, "insert position too large.");
    auto it = first;
    for(auto idx = 0; idx != pos - 1; ++idx)
        it = it->next;
    auto node = std::make_shared<Node>(item,it->next);
    it->next = node;
    ++sz;
}

template <typename T>
void ADT::LinkedList<T>::erase_front(){
    if(empty())
        throw(std::runtime_error("erase on empty list"));
    first = first->next;
    --sz;
}

template <typename T>
void ADT::LinkedList<T>::erase_back(){
    if(empty())
        throw(std::runtime_error("erase on empty list"));
    auto it = first;
    for(; it->next->next != nullptr; it = it->next);
    it->next = nullptr;
    --sz;
}

template <typename T>
T ADT::LinkedList<T>::erase(size_type pos){
    // 0 1 2 3 4 5 6 7 8 9
    check(pos, "erase position too large");
    auto it = first;
    for(auto idx = 0; idx != pos - 1; ++idx)
        it = it->next;
    auto ret = it->next->val;
    it->next = it->next->next;
    --sz;
    return ret;
}

template <typename T>
T &ADT::LinkedList<T>::front() const{
    if(empty())
        throw(std::runtime_error("front on empty list."));
    return first->val;
}

template <typename T>
T &ADT::LinkedList<T>::back() const{
    if(empty())
        throw(std::runtime_error("back on empty list."));
    auto it = first;
    for(;it->next != nullptr; it = it->next);
    return it->val;
}

template <typename T>
T &ADT::LinkedList<T>::get(size_type pos) const{
    check(pos, " access is out of range.");
    auto it = first;
    for(auto idx = 0; idx != pos; ++idx)
        it = it->next;
    return it->val;
}

