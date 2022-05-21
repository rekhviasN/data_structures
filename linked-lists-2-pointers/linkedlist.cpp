#include "linkedlist.h"

LinkedList::LinkedList() {
    	head = NULL;
}

LinkedList::~LinkedList() {
	//deallocate list
	clearList();
}


bool LinkedList::addNode(int id, string * data ){
	bool success = true;

	if(id < 1){
		success = false;
	}else{

		Node * node = new Node;
		node->data.id = id;
		node->data.data = *data;
		node->next = NULL;
		node->prev = NULL;

		if(!head){
			head = node;
		}else{
			Node * curr = head;
			// iterate through list, passing all nodes with smaller ids
			while(curr->data.id < id && curr->next){
				curr = curr->next;
			}
			// addresses tail case where tail id is smaller than new id  
			if(curr->data.id < id && !(curr->next)){
				curr->next = node;
				node->prev = curr;
			// checks to see if the existing node equal id passed in
			}else if(curr->data.id == id){
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
	
	return success;
}

bool LinkedList::deleteNode(int id){
	bool success = false;
	Node * curr = head; 
	while(curr){
		if(curr->data.id == id){
			// head case
			if(curr->data.id == head->data.id){
				head = head->next;
				delete curr;
			// tail case
			}else if(!curr->next){
				curr->prev->next = NULL;
				delete curr;
			// middle case
			}else{
				Node * previous = curr->prev;
				Node * next = curr->next;
				previous->next = next;
				next->prev = previous;
				delete curr; 
			}
			success = true;
			break;
		}
		curr = curr->next;
	}
	return success;
}

bool LinkedList::getNode(int id, Data* data){
	Node * curr = head;
	bool success = false;
	while(curr){
		if(curr->data.id == id){
			data->id = id;
			data->data = curr->data.data;
			success = true;
			break;
		}
		curr = curr->next;
	}
	return success;
}

void LinkedList::printList(bool backward){
	cout << "printlist top" << endl;
	Node * curr = head;

	cout << "printlist calling getCount()..." << endl;
	int count = getCount();
	int countCopy = count;
	Node * store[count];

	while(curr){
		if(backward){
			store[count-1] = curr;
			count--;
		}else{
			cout << "Forwards - ID: " << curr->data.id << " and data: " << curr->data.data << endl;
		}
		curr = curr->next;
	}

	if(backward){
		for(int k=0; k < countCopy; k++){
			cout <<"Backwards - ID : " << store[k]->data.id << " and data: " << store[k]->data.data << endl;
		}
	}
	cout << "printlist == done" << endl;
		
}

int LinkedList::getCount(){
	int count = 0;
	cout << "getCount top"<< endl;
	if(head){
		cout << "getCount - A" << endl;
		Node *ptr = head;
		cout << "getCount - B" << endl;
		while(ptr){
			cout << "getCount - C" << endl;
			count++;
			cout << "getCount - D" << endl;
			ptr = ptr->next;
			cout << "getCount - E" << endl;
		}
	}
	cout << "getCount bottom" << endl;
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

bool LinkedList::exists(int id){
	bool found = false;
	Node * curr = head;
	while(curr){
		if(curr->data.id == id){
			found = true;
			break;
		}
		curr = curr->next;
	}
	return found;
}

