//
// Author           : skannan
// Timestamp        : 8/17/21, 11:38 PM
// Compile command  : g++ -Wall -o exec josephus.cpp -I ~/CLionProjects/cpp-primer/include
// Description      : Solution to the famous Josephus problem using Ring Buffer ADT
//

#include <string>
#include "../lib/RingBuffer.h"

int josephus(int N, int M) {
    auto field = new ADT::RingBuffer<int>(1);
    for (auto i = 1; i < N; ++i)
        field->enqueue(i + 1);
    auto node = field->get_first_node();
    while(field->size() > 1){
        auto it = node;
        for(auto i = 0; i != M - 1; ++i)
            it = it->next;

        auto yield = it->next;
        field->erase(it);
        node = yield;
    }
    return field->front();
}