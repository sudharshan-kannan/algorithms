//
// Author           : skannan
// Timestamp        : 8/17/21, 11:24 PM
// Compile command  : g++ -Wall -o exec tRingBuffer.cpp -I ~/CLionProjects/cpp-primer/include
// Description      : A client code for Ring Buffer ADT (see also Josepehus problem)
//

#include <string>
#include <iostream>
#include "../lib/RingBuffer.h"

void checkRingBufferOfStrings(){
    auto circularQueue = new ADT::RingBuffer<std::string>("achyuth");
    circularQueue->enqueue("suba");
    circularQueue->enqueue("ajay");
    circularQueue->enqueue("vijay");
    circularQueue->erase(3);

    std::cout << "front : " << circularQueue->front() << std::endl;
    std::cout << "back : " << circularQueue->back() << std::endl;
    std::cout << "size : " << circularQueue->size() << std::endl;
    circularQueue->dequeue();
//    circularQueue->dequeue();
//    circularQueue->dequeue();
    std::cout << "front : " << circularQueue->front() << std::endl;
//    circularQueue->enqueue("appa");
    std::cout << "size : " << circularQueue->size() << std::endl;
    std::cout << "back : " << circularQueue->back() << std::endl;
}


