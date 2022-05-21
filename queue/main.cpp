#include "main.h"

void make_test_cases(int *ids, char **data, int num_cases) {

    for (int i = 0; i < num_cases; i++) {
        ids[i] = rand() % MAX_ID + 1;
        for (int j = 0; j < BUFFER_SIZE - 1; j++) {
            data[i][j] = 'a' + i;
        }
        data[i][BUFFER_SIZE - 1] = '\0';
    }
}

void display_test_cases(int *ids, char **data, int num_cases) {
    cout << "Displaying test cases..." << endl;
    for (int i = 0; i < num_cases; i++) {
        cout << ids[i] << ": " << data[i] << endl;
    }
}

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

    // declare the queue
    Queue queue;
    
    /*****************************************
     * Perform your queue tests starting here
     *****************************************/
    
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

    // testing isEmpty() on empty queue
    if (queue.isEmpty()) {
        cout << "queue is empty" << endl;
    } else {
        cout << "queue is NOT empty" << endl;
    }
  
    queue.peek(&myData);
    if(myData.id == -1 && myData.information.empty()){
        cout << "peek underflow: -1 and empty str returned" << endl;
    } else {
        cout << "peeked : " << myData.id <<" " << myData.information << endl;
    }

    queue.dequeue(&myData);
    if(myData.id == -1 && myData.information.empty()){
        cout << "dequeue underflow: -1 and empty str returned" << endl;
    } else {
        cout << "dequeueped : " << myData.id <<" " << myData.information << endl;
    }
    
    cout << endl;
    /************************************************
    ******** FILLING AND FULL TESTS *****************
    ************************************************/
    
    cout << "Testing full operations." << endl;
    cout << "=====================================================" << endl;

    cout << "Filling queue with 5-25 test cases" << endl;

    for(int k=0; k < number_test_cases; k++){
        info = string(data[k]);
        if(queue.enqueue(ids[k], &info)){
            cout << "enqueueing Data with id " << ids[k] << " and info attribute of " << info << endl;
        }else{
            cout << "overflow: failed to enqueue Data with id " << ids[k] << " and info attribute of " << info << endl;
        }
    }

    cout << endl;
    // testing isEmpty() on full queue
    if (queue.isEmpty()) {
        cout << "queue is empty / something went wrong" << endl;
    } else {
        cout << "queue is NOT empty / as expected" << endl;
    }
    cout << endl;

    // testing peek() and dequeue() on full queue

    if(queue.peek(&myData)){
        cout << "peeked: id of " << myData.id << ", info of " << myData.information << endl;
    } else {
        cout << "peek underflow : queue is empty" << endl;
    }
    
    
    if(queue.dequeue(&myData)){
        cout << "dequeueped: id of " <<myData.id <<" info of " << myData.information  << endl;
    }else{
        cout << "dequeue underflow : queue is empty, id of " << myData.id << " info of " << myData.information << endl;
    }

    // testing peek() after dequeue()
    if(queue.peek(&myData)){
        cout << "peeked: id of " << myData.id << ", info of " << myData.information << endl;
    } else {
        cout << "peek underflow : queue is empty" << endl;
    }
    cout << endl;

    // // /************************************************
    // // ******** EMPTYING AND EMPTY TESTS ***************
    // // ************************************************/

    cout << "Testing peek and dequeue, and emptying queue..." << endl;
    cout << "=====================================================" << endl;

    // testing dequeueping and peeking whole queue + beyond 
    for (int i = 0; i < QUEUE_SIZE*2; i++){
        if(queue.peek(&myData)){
            cout << "peeked: id of " << myData.id << " information of " << myData.information  << endl;
        } else {
            cout << "peek underflow error: queue is empty" << endl;
        }
        if(queue.dequeue(&myData)){
            cout << "dequeueped: id of " << myData.id << " information of " << myData.information << endl;
        }else {
            cout << "dequeue underflow error: queue is empty" << endl;
        }
    }

    // testing isEmpty() when queue is emptied 
    if (queue.isEmpty()) {
        cout << "queue is empty / as expected" << endl;
    } else {
        cout << "queue is NOT empty / something went wrong" << endl;
    }

    //testing peek() and dequeue() on empty queue

    if(queue.peek(&myData)){
        cout << "peeked: id of " << myData.id << ", info of " << myData.information << endl;
    } else {
        cout << "peek underflow : queue is empty" << endl;
    }
    
    
    if(queue.dequeue(&myData)){
        cout << "dequeueped: id of " <<myData.id <<" info of " << myData.information  << endl;
    }else{
        cout << "dequeue underflow : queue is empty" << endl;
    }
    cout << endl;

    // // /************************************************
    // // ******** ATTRIBUTE ERROR TESTING  ***************
    // // ************************************************/

    cout << "Testing enqueueing 0 as ID..." << endl;
    info = string(data[0]);
    if(queue.enqueue(0, &info)){
        cout << "successfully enqueueed Data with ID of 0 / unexpected" << endl;
    }else{
        cout << "attribute error: Failed to enqueue Data with ID of 0 / expected" << endl; 
    }

    cout << endl;

    cout << "Testing enqueueing negative ID values..." << endl;
    int negativeID;
    for(int k=0; k < QUEUE_SIZE; k++){
        info = string(data[k]);
        negativeID = 0 - ids[k];
        if(queue.enqueue(negativeID, &info)){
            cout << "enqueueing Data with id " << negativeID << " and info attribute of " << info << endl;
        }else{
            cout << "attribute error: failed to enqueue Data with negative id " << negativeID << endl;
        }
    }

    cout  << endl;

    cout << "Testing enqueueing empty strings..." << endl;
    for(int k=0; k < QUEUE_SIZE; k++){
        info = "";
        if(queue.enqueue(ids[k], &info)){
            cout << "enqueueing Data with id " << ids[k] << " and info attribute of an empty string";
        }else{
            cout << "attribute error: failed to enqueue Data with id " << ids[k] << " and info attribute of an empty string" << info << endl;
        }
    }

    // /************************************************
    // ******** RANDOM TESTS ***************************
    // ************************************************/
    
    cout << "Random testing..." << endl;
    // filling the queue half way with random numbers to begin random tests
    for (int i = 0; i< (QUEUE_SIZE / 2); i++) {
        info = string(data[i]);
        if(queue.enqueue(ids[i], &info)){
            cout << "enqueueing Data with id " << ids[i] << " and info attribute of " << info << endl;
        }else{
            cout << "overflow: failed to enqueue Data with id " << ids[i] << " and info attribute of " << info << endl;
        }
    }

    int choice = rand() % CHOICES + 1;
    int randomIndex = rand() % (QUEUE_SIZE/2);
    for(int i=0; i < RANDOM_TRIES; i++){
        info = string(data[randomIndex]);
        switch (choice) {
            case 1:
            case 2:
                // enqueue
                if (queue.enqueue(ids[randomIndex], &info)) {
                    cout << "enqueueed: id of " << ids[randomIndex] << ", information of " << info<< endl;
                } else {
                    cout << "overflow error" << endl;
                }
                break;
            case 3:
            case 4:
                // dequeue
                if(queue.dequeue(&myData)){
                    cout <<"dequeueped: id of " << myData.id <<", information of " << myData.information << endl;
                }else{
                    cout << "dequeue underflow error: queue is empty" << endl;
                }
                break;
            case 5:
                // peek
                if(queue.peek(&myData)){
                    cout << "peeked: id of " << myData.id <<", information of " << myData.information << endl;
                } else {
                    cout << "peek underflow error: queue is empty" << endl;
                }
                break;
            case 6:
                // isempty
                if (queue.isEmpty()) {
                    cout << "queue is empty" << endl;
                } else {
                    cout << "queue is NOT empty" << endl;
                }
                break;
        }
        choice = rand() % CHOICES + 1;
        randomIndex = rand() % (QUEUE_SIZE/2);
    }

    cout << "Testing complete." << endl;

    return 0;
}
