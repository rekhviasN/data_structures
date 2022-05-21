#include "linkedList.h"

LinkedList::LinkedList() {
    	this->head = NULL;
}

LinkedList::~LinkedList() {
	//deallocate list
	this->clearList();
}

bool LinkedList::createVertex(int id){

	bool status = false;
	if(head == NULL){
		Node * node = new Node;
		node->id = id;
		node->weight = 0;
		node->next = NULL;
		node->prev = NULL;
		head = node;
		status = true;
	}
	
	return status;
}

bool LinkedList::addEdge(int id, int weight = 0 ){
	bool success = true;

	if(id < 1){
		success = false;
	}else{

		Node * node = new Node;
		node->id = id;
		node->weight = weight;
		node->next = NULL;
		node->prev = NULL;

		if(!this->head ){
			this->head = node;
		}else{

			Node * curr = head->next;

			if(!curr){
				head->next = node;
			}else{
			// iterate through list, passing all nodes with smaller ids
				while(curr->id < id && curr->next){
					curr = curr->next;
				}
				// addresses tail case where tail id is smaller than new id  
				if(curr->id < id && !(curr->next)){
					curr->next = node;
					node->prev = curr;
				// checks to see if the existing node equal id passed in
				}else if(curr->id == id){
					success = false;
				// checks to see if the head needs to be replaced, if there's only 1 existing node
				}else if(!curr->prev){
					head = node;
					node->next = curr;
					curr->prev = node;
				}else{
					// places node in the middle of list - curr id is greater than id 
					node->next = curr;
					node->prev = curr->prev;
					Node * previous = curr->prev;
					previous->next = node;
					curr->prev = node; 
				}
			}
		}
	}
	
	return success;
}

bool LinkedList::removeEdge(int id){

	bool success = false;
	Node * curr = head;	
	if(!curr->next){
		success = false;
	}else{
		while(curr->next && (curr->next->id != id)){
			curr = curr->next;
		}
		if(curr->next && curr->next->id==id){
			if(curr->next->next){
				Node * newNext = curr->next->next;
				newNext->prev = curr;
				delete curr->next;
				curr->next = newNext;
				success = true;
			}else{
				delete curr->next;
				curr->next = NULL;
				success = true;
			}
		}else{
			success = false;
		}
	}
	return success;
}


void LinkedList::printList(bool backward){
	Node * curr = head;

	int count = this->getCount();
	int countCopy = count;
	Node * store[count];
	while(curr){
		if(backward){
			store[count-1] = curr;
			count--;
		}else{
			cout << "Forwards - ID: " << curr->id << endl;
		}
		curr = curr->next;
	}
	if(backward){
		for(int k=0; k < countCopy; k++){
			cout <<"Backwards - ID : " << store[k]->id  << endl;
		}
	}
	cout << "printlist == done" << endl;
		
}

int LinkedList::getCount(){
	int count = 0;
	if(head){
		Node *ptr = head;
		while(ptr){
			count++;
			ptr = ptr->next;
		}
	}
	return count;
}
	
bool LinkedList::clearList(){

	Node * curr = head;
	while(curr && curr->next){
		curr = curr->next;
		delete curr->prev;

	}
	delete curr;
	head = NULL;
	
    return true;

}


int LinkedList::getVertex(){
	return head->id;
}

