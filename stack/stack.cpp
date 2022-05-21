#include "stack.h"

Stack::Stack() {
    this->top = -1;
}

Stack::~Stack() {
    for(int k =0; k <= top; k++){
        delete stack[k];
    }
}

bool Stack::push(int id, const string * str) {
    bool pushed = false;
    // Check that there is room in the stack, int is positive, and that string is not empty
    if (top < STACK_SIZE - 1 && 
        (id > 0) &&
        (!str->empty())){

        Data *newData = new Data;
        newData->id = id;
        newData->information = *str;
        stack[++top] = newData;
        pushed = true;
    }
    return pushed;
}

bool Stack::pop(Data *ref){
    bool somethingToPop = true;

    if(top>-1){
        ref->id = stack[top]->id;
        ref->information = stack[top]->information;
        delete stack[top--];
    }else{
        ref->id = -1;
        ref->information = "";
        somethingToPop = false;
    }

    return somethingToPop;

}

bool Stack::peek(Data *ref){
	bool somethingToPop = true;

    if(top>-1){
        ref->id = stack[top]->id;
        ref->information = stack[top]->information;
    }else{
        ref->id = -1;
        ref->information = "";
        somethingToPop = false;
    }
    
    return somethingToPop;
}

bool Stack::isEmpty(){

    bool isEmpty = true;
    if(top > -1){
        isEmpty = false;
    }
    return isEmpty;
}
