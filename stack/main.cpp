#include "main.h"

int main() {

    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    // filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);

    // declare the stack
    Stack stack;
    
    // create a simple single ADT of type Data
    Data myData;
    myData.id = 1;
    myData.information = "Hello World";

    // declare a string variable 
    string info;

    /************************************************
    ******* EMPTY TESTS *****************************
    ************************************************/

    cout << "Beginning tests..." << endl << endl << "Testing empty operations." << endl;
    cout << "=====================================================" << endl;

    // testing isEmpty() on empty stack
    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }
  
    stack.peek(&myData);
    if(myData.id == -1 && myData.information.empty()){
        cout << "peek underflow: -1 and empty str returned" << endl;
    } else {
        cout << "peeked : " << myData.id <<" " << myData.information << endl;
    }

    stack.pop(&myData);
    if(myData.id == -1 && myData.information.empty()){
        cout << "pop underflow: -1 and empty str returned" << endl;
    } else {
        cout << "popped : " << myData.id <<" " << myData.information << endl;
    }
    
    cout << endl;
    /************************************************
    ******** FILLING AND FULL TESTS *****************
    ************************************************/
    
    cout << "Testing full operations." << endl;
    cout << "=====================================================" << endl;

    cout << "Filling stack with 5-25 test cases" << endl;

    for(int k=0; k < number_test_cases; k++){
        info = string(data[k]);
        if(stack.push(ids[k], &info)){
            cout << "pushing Data with id " << ids[k] << " and info attribute of " << info << endl;
        }else{
            cout << "overflow: failed to push Data with id " << ids[k] << " and info attribute of " << info << endl;
        }
    }

    cout << endl;
    // testing isEmpty() on full stack
    if (stack.isEmpty()) {
        cout << "stack is empty / something went wrong" << endl;
    } else {
        cout << "stack is NOT empty / as expected" << endl;
    }
    cout << endl;

    // testing peek() and pop() on full stack

    if(stack.peek(&myData)){
        cout << "peeked: id of " << myData.id << ", info of " << myData.information << endl;
    } else {
        cout << "peek underflow : stack is empty" << endl;
    }
    
    
    if(stack.pop(&myData)){
        cout << "popped: id of " <<myData.id <<" info of " << myData.information  << endl;
    }else{
        cout << "pop underflow : stack is empty, id of " << myData.id << " info of " << myData.information << endl;
    }

    // testing peek() after pop()
    if(stack.peek(&myData)){
        cout << "peeked: id of " << myData.id << ", info of " << myData.information << endl;
    } else {
        cout << "peek underflow : stack is empty" << endl;
    }
    cout << endl;

    /************************************************
    ******** EMPTYING AND EMPTY TESTS ***************
    ************************************************/

    cout << "Testing peek and pop, and emptying stack..." << endl;
    cout << "=====================================================" << endl;

    // testing popping and peeking whole stack + beyond 
    for (int i = 0; i < STACK_SIZE*2; i++){
        if(stack.peek(&myData)){
            cout << "peeked: id of " << myData.id << " information of " << myData.information  << endl;
        } else {
            cout << "peek underflow error: stack is empty" << endl;
        }
        if(stack.pop(&myData)){
            cout << "popped: id of " << myData.id << " information of " << myData.information << endl;
        }else {
            cout << "pop underflow error: stack is empty" << endl;
        }
    }

    // testing isEmpty() when stack is emptied 
    if (stack.isEmpty()) {
        cout << "stack is empty / as expected" << endl;
    } else {
        cout << "stack is NOT empty / something went wrong" << endl;
    }

    // testing peek() and pop() on empty stack

    if(stack.peek(&myData)){
        cout << "peeked: id of " << myData.id << ", info of " << myData.information << endl;
    } else {
        cout << "peek underflow : stack is empty" << endl;
    }
    
    
    if(stack.pop(&myData)){
        cout << "popped: id of " <<myData.id <<" info of " << myData.information  << endl;
    }else{
        cout << "pop underflow : stack is empty" << endl;
    }
    cout << endl;

    /************************************************
    ******** ATTRIBUTE ERROR TESTING  ***************
    ************************************************/

    cout << "Testing pushing 0 as ID..." << endl;
    info = string(data[0]);
    if(stack.push(0, &info)){
        cout << "successfully pushed Data with ID of 0 / unexpected" << endl;
    }else{
        cout << "attribute error: Failed to push Data with ID of 0 / expected" << endl; 
    }

    cout << endl;

    cout << "Testing pushing negative ID values..." << endl;
    int negativeID;
    for(int k=0; k < STACK_SIZE; k++){
        info = string(data[k]);
        negativeID = 0 - ids[k];
        if(stack.push(negativeID, &info)){
            cout << "pushing Data with id " << negativeID << " and info attribute of " << info << endl;
        }else{
            cout << "attribute error: failed to push Data with negative id " << negativeID << endl;
        }
    }

    cout  << endl;

    cout << "Testing pushing empty strings..." << endl;
    for(int k=0; k < STACK_SIZE; k++){
        info = "";
        if(stack.push(ids[k], &info)){
            cout << "pushing Data with id " << ids[k] << " and info attribute of an empty string";
        }else{
            cout << "attribute error: failed to push Data with id " << ids[k] << " and info attribute of an empty string" << info << endl;
        }
    }

    /************************************************
    ******** RANDOM TESTS ***************************
    ************************************************/
    
    cout << "Random testing..." << endl;
    // filling the stack half way with random numbers to begin random tests
    for (int i = 0; i< (STACK_SIZE / 2); i++) {
        info = string(data[i]);
        if(stack.push(ids[i], &info)){
            cout << "pushing Data with id " << ids[i] << " and info attribute of " << info << endl;
        }else{
            cout << "overflow: failed to push Data with id " << ids[i] << " and info attribute of " << info << endl;
        }
    }

    int choice = rand() % CHOICES + 1;
    int randomIndex = rand() % (STACK_SIZE/2);
    for(int i=0; i < RANDOM_TRIES; i++){
        info = string(data[randomIndex]);
        switch (choice) {
            case 1:
            case 2:
                // push
                if (stack.push(ids[randomIndex], &info)) {
                    cout << "pushed: id of " << ids[randomIndex] << ", information of " << info<< endl;
                } else {
                    cout << "overflow error" << endl;
                }
                break;
            case 3:
            case 4:
                // pop
                if(stack.pop(&myData)){
                    cout <<"popped: id of " << myData.id <<", information of " << myData.information << endl;
                }else{
                    cout << "pop underflow error: stack is empty" << endl;
                }
                break;
            case 5:
                // peek
                if(stack.peek(&myData)){
                    cout << "peeked: id of " << myData.id <<", information of " << myData.information << endl;
                } else {
                    cout << "peek underflow error: stack is empty" << endl;
                }
                break;
            case 6:
                // isempty
                if (stack.isEmpty()) {
                    cout << "stack is empty" << endl;
                } else {
                    cout << "stack is NOT empty" << endl;
                }
                break;
        }
        choice = rand() % CHOICES + 1;
        randomIndex = rand() % (STACK_SIZE/2);
    }

    cout << "Testing complete." << endl;

    return 0;
}
