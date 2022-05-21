#include "queue.h"

Queue::Queue() {
    this->front = -1;
    this->rear = -1;
}

Queue::~Queue() {

    int min = fmin(this->front, this->rear);
    int max = fmin(this->front, this->rear);
    for(int k =min; k <= max; k++){
        delete queue[k];
    }
}

bool Queue::enqueue(int id, const string * str) {

    bool pushed = false;
      // Check that int is positive, and that string is not empty
    if(id > 0 && !str->empty() && 
        // check that there is space on the queue
        (rear <= front-2 || 
        (rear == front) ||
        (rear > front && (rear<QUEUE_SIZE-1))
        )){
        Data *newData = new Data;
        newData->id = id;
        newData->information = *str;


        if(front == -1){
            queue[0] = newData;
            front = 0;
            rear = 0; 
        }else if(rear < front-2 || 
          (rear >= front && (rear < QUEUE_SIZE-1))){
           queue[++rear] = newData;
        } else if(rear == QUEUE_SIZE-1 && (front > 0)){
            queue[0] = newData;
            rear = 0;
        }
        pushed = true;
    }
    return pushed;
}


bool Queue::dequeue(Data *ref){
    bool somethingToPop = true;
    std::cout << "1" << std::endl;
    if(front > -1){
        ref->id = queue[front]->id;
        ref->information = queue[front]->information;
        delete queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }else if (front == QUEUE_SIZE-1){
            front = 0;
        }else{
            front++;
        }
    }else{
        ref->id = -1;
        ref->information = "";
        somethingToPop = false;
    }

    return somethingToPop;

}

bool Queue::peek(Data *ref){
	bool somethingToPop = true;

    if(front>-1){
        ref->id = queue[front]->id;
        ref->information = queue[front]->information;
    }else{
        ref->id = -1;
        ref->information = "";
        somethingToPop = false;
    }
    
    return somethingToPop;
}

bool Queue::isEmpty(){

    bool isEmpty = true;
    if(front > -1){
        isEmpty = false;
    }
    return isEmpty;
}
