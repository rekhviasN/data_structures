#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define HASHTABLESIZE 15

#include <iostream>
#include <string>
#include "data.h"
#include "linkedlist.h"

using std::cout;
using std::endl;
using std:: string;


class LinkedList {

public:
	LinkedList();
	~LinkedList();
	bool addNode(int, string*);

private:
	Node *head;
};

class HashTable {

public:
	HashTable();
	~HashTable();
	bool insertEntry(int, string*);
	string getData(int);
	bool removeEntry(int);
	int getCount();
	void printTable();
	void emptyHashTable();
	

private:
	int hash(int);
	int count;
	LinkedList *hashtable[HASHTABLESIZE];
};





#endif /* HASH_TABLE_H */