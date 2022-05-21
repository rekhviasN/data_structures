#include "main.h"

int main(int argc, char** argv) {

    // Stores data up until array size exceeds, returns 0 for overflow condition
    Stack s1;
    for(int k =0; k < SIZE+1 ; k++){
        cout << s1.push(k);
    } 
    // Peek successfull obtains last value, SIZE-1
    cout << s1.peek() << endl; 

    // Removes all values, then tests pop() and peek() when stack is empty
    for(int k =0; k < SIZE; k++){
        cout << s1.pop() << endl;
    }

    try{
        cout << s1.pop() << endl; 
    }catch(underflow_error& message){
        cout << message.what() <<endl;
    }
    try{
        cout <<s1.peek() << endl;
    }catch(out_of_range& message){
        cout << message.what() <<endl;
    }

    // isEmpty() correctly returns when stack is empty 
    cout << s1.isEmpty() <<endl; 
    //After stack has been emptied, push() and peek() is successful 
    cout << s1.push(1) << endl;
    cout << s1.peek() << endl;
    // isEmpty() correctly returns 0 when stack is not empty
    cout << s1.isEmpty() << endl;
    // Reset stack size to 0;
    s1.pop();
    cout << s1.isEmpty() << endl;
    // After running all methods, stores data up until array size exceeds, returns 0 for overflow condition
    for(int k =0; k < SIZE+1 ; k++){
        cout << s1.push(k);
    } 

    // Makes sure rand() will generate a random number each time program is run
    srand((int)time(0));

    // Tests pushing far beyond the stack size 
    for(int t =0 ; t < 5; t++){
        Stack s1;
        int random = (rand()%(SIZE*10))+SIZE;
        cout << "Attempting to push " << random << " values to the stack of size " << SIZE << endl;
        for(int k = 0; k < random ; k++){
            cout << s1.push(k) << endl;
        }
    }

    // Tests poping below stack floor  
    for(int t =0 ; t < 5; t++){
        // Create and fill stack to maximum capacity
        Stack s1;
        for(int k = 0; k < SIZE ; k++){
            s1.push(k);
        }
        // Create random count to pop off stack 
        int random = (rand()%(SIZE*10))+SIZE;
        cout << "Attempting to pop " << random << " values from the stack of size " << SIZE << endl;
        for(int k = 0; k < random; k++){
            try{
                cout << s1.pop() << endl;
            }catch(underflow_error& message){
                cout << message.what() <<endl;
            }
        }
    }
    
	return 0;
}