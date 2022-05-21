#include "graph.h"

Graph::Graph(){

}

Graph::~Graph(){
	for(int k=0; k < adjacencyList.size(); k++){
		adjacencyList.at(k)->clearList();
		delete adjacencyList.at(k);
		adjacencyList.erase(adjacencyList.begin());
	}
}

void Graph::displayVertices(){
	cout << "list size is " << adjacencyList.size() <<endl;
	for(int k=0; k < adjacencyList.size(); k++){
		cout<<adjacencyList.at(k)->getVertex() << endl;
		adjacencyList.at(k)->printList();
	}
}
int Graph::getVerticesCount(){
	return adjacencyList.size();
}

bool Graph::vertexExists(int id){
	bool exists = false;
  	for(int k=0; k < getVerticesCount(); k++){
  		if(adjacencyList.at(k)->getVertex() == id){
  			exists = true;
  		}
  	}
	return exists;
}

bool Graph::addVertex(int id, vector<int> * edges = {}){
	bool status = true;
	if((edges->size() !=2 && adjacencyList.size()) || 
		(adjacencyList.size() == GRAPHSIZE) ||
		(id < 1)
		){
		status = false;
	}else {
	  	//Iterate through graph to see if this node exists
	  	status = vertexExists(id) ? false : true;
	  	//Iterate through the edges to make sure they represent valid vertices		
		if( edges->size() && !vertexExists(edges->at(0)) ){
			status = false;
		}

	  	if(status){
	  		LinkedList * newVertice = new LinkedList;
	  		newVertice->createVertex(id);
	  		adjacencyList.push_back(newVertice);
		  	
		  	// Iterate over all of the edge tuples and place them appropriately
			if(edges->size()){
		  		int neighborNodeId = edges->at(0);
		  		int weight = edges->at(1);

		  		// Find vertices with the relevant ID
		  		for(int k=0; k < getVerticesCount(); k++){
			  		if(adjacencyList.at(k)->getVertex() == neighborNodeId){	
			  			addEdge(newVertice, adjacencyList.at(k), weight);
			  		}
			  	} 	
		  	}
		}
	}

	return status;
}


bool Graph::addEdge(LinkedList * vertexA, LinkedList* vertexB, int weight){
	bool status; 
	vertexA->addEdge(vertexB->getVertex(), weight);
	vertexB->addEdge(vertexA->getVertex(), weight);

	return true;
}


bool Graph::removeEdge(int id, int id2){
	bool found1 = false;
	bool found2 = false;
	vector<int> vertexesToDestroy;
	for(int k =0; k < adjacencyList.size(); k++){
		int vertex = adjacencyList.at(k)->getVertex();
		if(vertex == id){
			found1 = adjacencyList.at(k)->removeEdge(id2);
			if(adjacencyList.at(k)->getCount() == 1){
				vertexesToDestroy.push_back(id);
			}
		}else if(vertex ==id2){
			found2= adjacencyList.at(k)->removeEdge(id);
			if(adjacencyList.at(k)->getCount() == 1){
				vertexesToDestroy.push_back(id2);
			}
		}
	}
	for(int k= 0 ; k < vertexesToDestroy.size(); k++){
		removeVertex(vertexesToDestroy.at(k));
	}
	return found1 && found2 ? true : false;
}

// Destroys the vertex only if there are no edges attached to it; edges should be removed prior
bool Graph::removeVertex(int id){
	bool success = false;
	for(int k=0; k < adjacencyList.size(); k++){
		if(adjacencyList.at(k)->getVertex() == id){
			//no edges condition
			if(adjacencyList.at(k)->getCount()==1){
				 delete adjacencyList.at(k);
				 adjacencyList.erase(adjacencyList.begin()+k);
			}
		}
	}

	return success;
}

