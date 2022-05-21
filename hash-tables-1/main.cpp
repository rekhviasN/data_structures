#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;
    
    // create your hash table object here

    HashTable hash;
    
    // show it is empty by calling getCount and printTable
    cout << "Count at beginning: " << endl;
    cout << hash.getCount() << endl;
    cout << endl;
    cout << "\tPrinting empty table..." << endl;
    hash.printTable();
    // try and put ALL the test data into the table and show what happens
    cout << endl;
    cout <<"\tAdding data..." << endl;
    for(int k = 0; k < testdatasize; k++){
        cout<< "Attempting to add id " << ids[k] << " with info " << strs[k] << endl;
        cout <<"Result: " << hash.insertEntry(ids[k], &strs[k]) << endl;
    }
    cout << endl;
    cout <<"\tPrinting table..." <<endl;
    hash.printTable();
    cout <<endl;

    cout << "\tThere are " << hash.getCount() << " nodes." << endl;
    cout << endl; 
    //randomly getting a few nodes
    int getid;
    string res;
    int randomIndex;
    cout << "Randomly getting data for ids..." << endl;
    for (int i = 0; i < 10; i++) {
        randomIndex = rand() % testdatasize;
        getid = ids[randomIndex];
        res = hash.getData(getid);
        if (res == "") {
            cout << "failed to find " << getid << ": " << res << endl;
        } else {
            cout << "found " << getid << ", data: " << res << endl;
        }
    }

    cout << endl;

    // deleting from the list random ids from the test data
    cout << "Randomly deleting a few nodes and checking for them..." << endl;
    int delid;
    for (int i = 0; i < 5; i++) {
        randomIndex = rand() % (testdatasize/2);
        delid = ids[randomIndex];
        cout << "deleting " << delid << "... " << endl;
        if (hash.removeEntry(delid)) {
            cout << "success" << endl;
        } else {
            cout << "failed" << endl;
        }
        cout <<"searching for deleted entry " << delid << "..." << endl;
        if(hash.getData(delid) == ""){
            cout << "not found, as expected" <<endl;
        }else{
            cout << "ERROR: deleted id was found" << endl; 
        }

    }
    cout << endl;
    
    cout << "checking table...\n";
    cout << "\tThere are " << hash.getCount() << " nodes." << endl;
    hash.printTable();
    cout << endl;

    cout << "clearing list...";
    hash.emptyHashTable();
    cout << "done" << endl << endl;

    cout << "checking list...\n";
    cout << "\tThere are " << hash.getCount() << " nodes." << endl;
    hash.printTable();
    cout << endl;

    //Adding nodes after emptying list
    cout <<"\tAdding data..." << endl;
    for(int k = 0; k < testdatasize; k++){
        cout<< "Attempting to add id " << ids[k] << " with info " << strs[k] << endl;
        cout <<"Result: " << hash.insertEntry(ids[k], &strs[k]) << endl;
    }
    cout << endl;
    cout <<"\tPrinting table..." <<endl;
    hash.printTable();
    cout <<endl;
    cout << endl;
    cout <<"\tPrinting table..." <<endl;
    hash.printTable();
    cout <<endl;

    cout << "\tThere are " << hash.getCount() << " nodes." << endl;
    cout << endl; 
    
    return 0;
}
