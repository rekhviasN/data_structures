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
	bool createVertex(int);
	bool addEdge(int, int);
	bool removeEdge(int);
	void printList(bool = false);
	int getCount();
	bool clearList();
	int getVertex();

	Node *head;

private:
	
};



#endif /* LINKED_LIST_H */