#include "main.h"

int main() {
   
    // create graph object
    Graph graph;
    
    cout << "Count at beginning: " << endl;
    cout << graph.getVerticesCount() << endl;
    cout << endl;

    cout << "Displaying vertices:" << endl;
    graph.displayVertices();
    cout << "---------------" << endl;
    cout << "end display" << endl;

    cout << "Adding initial vertex with no edges succeeds" << endl;
    vector<int> vec;
    cout << graph.addVertex(12,&vec) << endl;
    graph.displayVertices();

    cout << "Adding dupe vertex id fails " << endl;

    vector <int> connectionAndWeight2 = {12,4};
    cout << graph.addVertex(12, &connectionAndWeight2) << endl;
    graph.displayVertices();

    cout <<"Adding new vertex id but empty edges list fails" << endl;
    cout <<graph.addVertex(13, &vec) << endl;
    graph.displayVertices();

    cout <<"Adding new vertex id with a non-tuple fails" << endl;
    vector <int> connectionAndWeight3 = {12};
    cout <<graph.addVertex(13, &connectionAndWeight3) << endl;
    graph.displayVertices();
    
    cout <<"Adding new vertex id with non-existant edge fails" << endl;
    vector <int> connectionAndWeight4 = {90,4};
    cout << graph.addVertex(13, &connectionAndWeight4) << endl;
    graph.displayVertices();

    cout <<"Adding new vertex id with existant edge succeeds" << endl;
    vector <int> connectionAndWeight5 = {12,4};
    cout << graph.addVertex(13, &connectionAndWeight5) << endl;
    graph.displayVertices();

    cout <<"Adding new vertex id with existant edge succeeds" << endl;
    vector <int> connectionAndWeight6 = {13,4};
    cout << graph.addVertex(14, &connectionAndWeight6) << endl;
    graph.displayVertices();

    cout <<"Adding new vertex id with existant edge succeeds" << endl;
    vector <int> connectionAndWeight7 = {12,90};
    cout << graph.addVertex(17, &connectionAndWeight7) << endl;
    graph.displayVertices();

    cout <<"Removing a valid edge is successfull" << endl;
    cout << graph.removeEdge(12,13) << endl;
    graph.displayVertices();

    cout <<"Attempting to remove nonexistant edge fails" <<endl;
    cout << graph.removeEdge(12,13) <<endl;
    graph.displayVertices();

    cout <<"Adding new vertex id with existant edge succeeds" << endl;
    vector <int> connectionAndWeight8 = {12,90};
    cout << graph.addVertex(20, &connectionAndWeight8) << endl;
    graph.displayVertices();

    cout <<"Attempting to add vertex with id < 1 fails" <<endl;
    vector <int> connectionAndWeight9 = {12,90};
    cout << graph.addVertex(0, &connectionAndWeight9) << endl;
    graph.displayVertices();

    cout <<"Removing edge between an otherwise unconnected node will remove it" <<endl;
    cout << graph.getVerticesCount() <<endl;
    cout << graph.removeEdge(20,12) <<endl;
    cout << graph.getVerticesCount() <<endl;
    graph.displayVertices();

    cout <<"You can remove all edges and have an empty list" <<endl;
    cout << graph.getVerticesCount() <<endl;
    cout << graph.removeEdge(12,17) <<endl;
    cout << graph.removeEdge(13,14) <<endl;
    cout << graph.getVerticesCount() <<endl;
    graph.displayVertices();

    //Creating test data
    
    vector <int> curr;
    vector <int> existingIDs;
    srand(time(0));

    cout << "Initialize graph with one vertex" << endl;
    int randomInitialID = rand() % 10+1;
    cout << graph.addVertex(randomInitialID,&vec) << endl;

    bool success;
    vector<int> validIDs;
    vector<int> validEdges;

    cout << "Add nodes beyond stack size beyond graph size" << endl;
    for(int k=0; k < GRAPHSIZE*2; k++){
        int id = ++randomInitialID;
        int connection = randomInitialID-1;
        int weight = rand() % 100;
        curr = {connection, weight};
        success = graph.addVertex(id, &curr);
        cout << success <<endl;
        if(success){
            validIDs.push_back(id);
            validEdges.push_back(connection);
        }
    }

    cout << "checking table...\n";
    cout << "\tThere are " << graph.getVerticesCount() << " nodes." << endl;
    graph.displayVertices();
    cout << endl;

    cout << "Remove random edges successfully" << endl;
    for(int k=0; k < graph.getVerticesCount()*10; k++){
        // find random vertice
        int randomIndex = rand() % validIDs.size();
        int randomID = validIDs.at(randomIndex);
        int randomEdge = validEdges.at(randomIndex);
        cout << graph.removeEdge(randomID, randomEdge) <<endl;
    }

    cout << "Removal of vertexes fails when edges are present " << endl;
    for(int k=0; k < validIDs.size(); k++){
        cout << validIDs[k] <<endl;
        cout << graph.removeVertex(validIDs[k]) <<endl;
    }

    cout << "Attemp to add bad data" << endl;
    cout << "Graph count before: " << graph.getVerticesCount() << endl;
    for(int k=0; k > -GRAPHSIZE*2; k--){
        int connection = randomInitialID-1;
        int weight = rand() % 100;
        curr = {connection, weight};
        cout << graph.addVertex(k, &curr) << endl;
    }

    cout << "Graph count after: " << graph.getVerticesCount() << endl;
    cout << endl;
    cout << "Attempt to add malformed data" << endl;
    cout << "Graph count before: " << graph.getVerticesCount() << endl;
    for(int k=0; k < GRAPHSIZE*2; k++){
        int connection = randomInitialID-1;
        int weight = rand() % 100;
        curr = {connection, weight};
        for(int i=0; i < rand() % 10; i++){
            curr.push_back(i);
        }
        cout << graph.addVertex(k, &curr) << endl;
    }
    cout << "Graph count after: " << graph.getVerticesCount() << endl;
    cout << endl;

    cout << "checking table...\n";
    cout << "\tThere are " << graph.getVerticesCount() << " nodes." << endl;
    graph.displayVertices();
    cout << endl;


    
    return 0;
}
