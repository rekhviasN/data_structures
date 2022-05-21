#include "stack.h"

Stack::Stack() {
    top = -1;
    stack_array = new int[SIZE];
}

Stack::~Stack() {
   // Deallocates memory reserved for stack_array
   delete stack_array;
}

// method to insert data into stack
bool Stack::push(int x){
    if(top == SIZE-1){
        return false;
    }else{
        stack_array[++top] = x;
        return true;
    }
}

// method to remove data from the stack
int Stack::pop(){
    return top > -1 ? stack_array[top--] : throw underflow_error("Stack underflow");
}

// method to check if stack is empty
bool Stack::isEmpty(){
    return top < 0 ? true : false;
}

// method to check last value added 
int Stack::peek(){
    return top > -1 ? stack_array[top] : throw out_of_range("Stack is empty");
}
