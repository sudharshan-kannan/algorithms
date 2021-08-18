////
//// Author           : skannan
//// Timestamp        : 8/16/21, 10:51 PM
//// Compile command  : g++ -Wall -o exec evaluate_expressions.cpp -I ~/CLionProjects/cpp-primer/include
//// Description      : Evaluate parenthesised expressions using Dijkstra's double stack algorithm
////
//
#include <string>
#include <iostream>
#include <sstream>
#include "../lib/Stack.h"
#include "../lib/LinkedList.cpp"

enum class OPERATION {ADD, SUB, MUL, DIV};

int eval_subexpression(int op1, int op2, const std::string &op);

int eval_subexpression(int op1, int op2, const std::string &op){
    if( op == "+") return op1 + op2;
    if( op == "-") return op1 - op2;
    if( op == "*") return op1 * op2;
    if( op == "/") return op1 / op2;
    throw(std::invalid_argument("operation not supported."));
}

int evaluate_expression(const std::string &input){
//    // 4 * ( ( 3 + 4 ) * ( ( 5 * 2 ) - 9 + 6 ) / 44 + 32 )
    auto operandStack = new ADT::Stack<int>();
    auto operatorStack = new ADT::Stack<std::string>();

    // Assumes operators and operands are separated by spaces
    std::istringstream istr(input);
    std::string s;
    while(istr >> s){
        if(s == " " || s == "(")
            continue;
        else if(s == "+" || s == "-" || s == "*" || s == "/") {
            operatorStack->push(s);
        }
        else if( s == ")"){
            std::string op = operatorStack->pop();
            int operand2 = operandStack->pop();
            int operand1 = operandStack->pop();
            operandStack->push(eval_subexpression(operand1, operand2, op));
        }
        else
            operandStack->push(std::stoi(s));
    }

    // Evaluate remaining expression in the stack if any
    int result = 0;
    while(!operandStack->empty()){
        int op2 = operandStack->pop();
        int op1 = operandStack->pop();
        std::string op = operatorStack->pop();
        result = eval_subexpression(op1,op2,op);
        if(!operandStack->empty())
            operandStack->push(result);
    }

    return result;
}