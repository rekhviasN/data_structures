#ifndef STACK_H
#define STACK_H

#include "data.h"
#define STACK_SIZE 10 

class Stack {

public:

    Stack(); // constructor
    ~Stack(); // destructor

    bool push(int, const string *);
    bool pop(Data *);
    bool peek(Data *);
    bool isEmpty();
    
private:

    int top; 
    Data *stack[STACK_SIZE];
};

#endif //STACK_H