#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string>
#include "data.h"

using std::cout;
using std::endl;
using std:: string;

class LinkedList {

public:
	LinkedList();
	~LinkedList();
	bool addNode(int, string*);
	bool deleteNode(int);
	bool getNode(int, Data*);
	void printList(bool = false);
	int getCount();
	bool clearList();
	bool exists(int);
	Node *head;

private:
	
};



#endif /* LINKED_LIST_H */