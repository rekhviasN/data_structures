#include "hashtable.h"

HashTable::HashTable(){
	count = 0;
}

HashTable::~HashTable(){
	this->emptyHashTable();
}

bool HashTable::insertEntry(int id, string * info){

	int index = this->hash(id);
	bool success = hashtable[index].addNode(id, info);
	if(success){
		count++;
	}
	
	return success ? true : false;
}

string HashTable::getData(int id){
	Data data; 

	int index = this->hash(id);
	bool success = hashtable[index].getNode(id, &data);
	
	return success ? data.data : "";
}

bool HashTable::removeEntry(int id){

	int index = this->hash(id);
	bool success = hashtable[index].deleteNode(id);
	if(success){
		count++;
	}
	
	return success;
}

int HashTable::getCount(){
	return count;
}

void HashTable::printTable(){
	for(int k=0; k < HASHTABLESIZE; k++){
		cout << "Entry " << k << ": " << endl;
		hashtable[k].printList();
	}
}

void HashTable::emptyHashTable(){
	for(int k=0; k < HASHTABLESIZE; k++){
		hashtable[k].clearList();
	}
	count = 0;
}

int HashTable::hash(int id){
	return  HASHTABLESIZE % id;
}