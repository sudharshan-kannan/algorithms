//
// Author           : skannan
// Timestamp        : 8/17/21, 10:07 PM
// Compile command  : g++ -Wall -o exec tQueue.cpp -I ~/CLionProjects/cpp-primer/include
// Description      : Client code for Queue ADT
//

#include <string>
#include <iostream>
#include "../lib/Queue.h"

void checkQueueOfStrings(){
    auto strQueue = new ADT::Queue<std::string>("achyuth");
    strQueue->enqueue("suba");
    strQueue->enqueue("ajay");
    strQueue->enqueue("vijay");
    std::cout << "front : " << strQueue->front() << std::endl;
    std::cout << "back : " << strQueue->back() << std::endl;
    std::cout << "size : " << strQueue->size() << std::endl;
    strQueue->dequeue();
    strQueue->dequeue();
    strQueue->dequeue();
    std::cout << "front : " << strQueue->front() << std::endl;
    strQueue->dequeue();
    std::cout << "size : " << strQueue->size() << std::endl;
}
