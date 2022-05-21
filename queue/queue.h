#ifndef QUEUE_H
#define QUEUE_H

#include <math.h> 
#include <iostream>
#include <string>
using std::string;

#define QUEUE_SIZE 10 

struct Data {
    int id;
    string information;
};

class Queue {

public:

    Queue(); // constructor
    ~Queue(); // destructor

    bool enqueue(int, const string *);
    bool dequeue(Data *);
    bool peek(Data *);
    bool isEmpty();
    
private:

    int front; 
    int rear;
    Data *queue[QUEUE_SIZE]; 
};

#endif //QUEUE_H