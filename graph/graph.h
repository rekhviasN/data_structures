#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>     
#include <string>
#include <vector>
#include <algorithm>
#include "linkedList.h"

#define GRAPHSIZE 15

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Graph {

public:
	Graph();
	~Graph();
	int getVerticesCount();
	bool addVertex(int, vector<int> *);
	bool removeVertex(int);
	bool addEdge(LinkedList *, LinkedList *, int);
	bool removeEdge(int, int);
	void displayVertices();

private:
	vector<LinkedList*> adjacencyList;
	bool vertexExists(int);
};

#endif /* GRAPH_H */