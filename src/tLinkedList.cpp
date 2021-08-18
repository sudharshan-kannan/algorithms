//
// Author           : skannan
// Timestamp        : 8/16/21, 4:45 PM
// Compile command  : g++ -Wall -o exec tLinkedList.cpp -I ~/CLionProjects/cpp-primer/include
// Description      : Client code for Linked List ADT
//

#include <string>
#include <iostream>
#include "../lib/LinkedList.cpp"

void checkLinkedListOfStrings() {
    // yashvi achyuth suba vijay
    // achyuth suba vijay
    // achyuth suba
    // achyuth suba amma appa
    auto strList = new ADT::LinkedList<std::string>("achyuth");
    strList->push_front("yashvi");
    strList->push_back("vijay");
    strList->insert("suba", 2);
    std::cout << strList->front() << " " << strList->back() << std::endl;
    strList->erase_front();
    std::cout << strList->front() << " " << strList->back() << std::endl;
    strList->erase_back();
    std::cout << strList->front() << " " << strList->back() << " size: " <<  strList->size() << std::endl;
    strList->push_back("amma");
    strList->push_back("appa");
    std::cout << strList->size() << std::endl;
}