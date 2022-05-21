#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <iostream>
#define SIZE 10

using std::cout;
using std::out_of_range;
using std::underflow_error;

class Stack {

    public:
        Stack();
        ~Stack();
        bool push(int);
        int pop();
        bool isEmpty();
      	int peek();

    private:
        int top;
        int *stack_array;
};


#endif //STACK_STACK_H

