//
// Author           : skannan
// Timestamp        : 8/16/21, 7:46 PM
// Compile command  : g++ -Wall -o exec tStack.cpp -I ~/CLionProjects/cpp-primer/include
// Description      : Client code for stack
//

#include <string>
#include <iostream>
#include "../lib/Stack.h"

void checkStackOfStrings(){
    auto strStack = new ADT::Stack<std::string>("achyuth");
    strStack->push("suba");
    strStack->push("ajay");
    strStack->push("vijay");
    std::cout << "top : " << strStack->top() << std::endl;
    std::cout << "size : " << strStack->size() << std::endl;
    strStack->pop();
    strStack->pop();
    strStack->pop();
    std::cout << "top : " << strStack->top() << std::endl;
    strStack->pop();
    std::cout << "size : " << strStack->size() << std::endl;
}