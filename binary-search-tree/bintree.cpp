#include "bintree.h"

BinTree::BinTree(){
	root= NULL;
	count= 0;
}

BinTree::~BinTree(){
	// clearTree();
}

bool BinTree::isEmpty(){
	return root ? true : false;
}

int BinTree::getCount(){
	return count;
}

bool BinTree::getRootData(Data * data){
	if(root){
		data->id = root->data.id;
		data->information = root->data.information;
	}else{
		data->id = -1;
		data->information = "";
	}
	return data;
}


//Overloaded functions 

void BinTree::clear(){
	clear(root);
	count = 0;
}
void BinTree::clear(DataNode* node){
	if(!node){
		return;
	}
	clear(node->left);
	clear(node->right);
	node->left = NULL;
	node->right = NULL;
	delete node;
	root = NULL;
}

bool BinTree::addNode(int id, string str){
	DataNode * node = new DataNode;
	node->data.id = id;
	node->data.information = str;
	node->left = NULL;
	node->right = NULL;

	bool success;
	if(id > 0 && !str.empty()){
		success = addNode(node, &root);
	}else{
		success = false;
	}
	return success;
}

bool BinTree::addNode(DataNode* newNode , DataNode** root ){
	bool success = false;

	if(!(*root)){
		*root = newNode;
		success = true;
		count++;
	}else if(newNode->data.id < (*root)->data.id){
		success = addNode(newNode, &(*root)->left);
	}else if(newNode->data.id > (*root)->data.id){
		success = addNode(newNode, &(*root)->right);
	}

	return success;
}



void BinTree::displayTree(){
	cout << "Count : " << count << endl;
	cout << "\tDisplay Preorder: " << endl;
	displayPreOrder();
	cout << "\tDisplay InOrder: " << endl;
	displayInOrder();
	cout << "\tDisplay PostOrder: " << endl;
	displayPostOrder();
}


bool BinTree::removeNode(int id){
	int tempcount = count;
	root = removeNode(id, root);
	return count < tempcount ? true : false;
}

DataNode* BinTree::removeNode(int id, DataNode* root){
	if(!root){
		return root;
	}

	if(id > root->data.id){
		root->right = removeNode(id, root->right);
	}else if(id < root->data.id){
		root->left = removeNode(id, root->left);
	}else if(root->data.id == id){
		if(root->right == NULL && root->left == NULL){
			delete root;
			root = NULL;
			count--;
		}else{
			DataNode * temp;
			if(root->left == NULL){
				temp = root->right;
				delete root;
				root = temp;
				count--;
			}else if(root->right == NULL){
				temp = root->left;
				delete root;
				root = temp;
				count--;
			}else{
				temp = minValueNode(root->right);
				root->data.id = temp->data.id;
				root->data.information = temp->data.information;
				root->right = removeNode(temp->data.id, root->right);
			}
		}
	}
	return root;
}


DataNode* BinTree::minValueNode(DataNode* node) {
	DataNode* current = node;
	while (current && current->left != NULL) {
		current = current->left; 
	}
	return current; 
}

bool BinTree::contains(int id){
	return contains(id, root);
}

bool BinTree::contains(int id, DataNode* root){
	bool success = false;
	if(root && (root->data.id == id)){
		success = true;
	}else if(root && (root->data.id < id)){
		success = contains(id, root->right);
	}else if(root && (root->data.id > id)){
		success = contains(id, root->left);
	} 
	return success; 
}

bool BinTree::getNode(Data* container , int id){
	bool success;
	if(id < 1){
		success = false;
	}else{
		success = getNode(container, id, root);
	}
	return success;
}

bool BinTree::getNode(Data* container, int id, DataNode* root){
	bool success = false;
	if(root && (root->data.id == id)){
		success = true;
		container->id= id;
		container->information = root->data.information;
	}else if(root && (root->data.id < id)){
		success = getNode(container, id, root->right);
	}else if(root && (root->data.id > id)){
		success = getNode(container, id, root->left);
	} 
	return success; 
}

int BinTree::getHeight(){
	return getHeight(root);
}

int BinTree::getHeight(DataNode* root){
	int lh = 0;
	int rh = 0;
	if(!root){
		return 0;
	}else{
		lh = getHeight(root->left) + 1;
		rh = getHeight(root->right) + 1;
		return fmax(lh,rh);
	}
}

void BinTree::displayPreOrder(){
	displayPreOrder(root);
}

void BinTree::displayPreOrder(DataNode * node){
	if(node){
		cout << "id: " << node->data.id << " , info: " << node->data.information << endl;
		displayPreOrder(node->left);
		displayPreOrder(node->right);
	}
}

void BinTree::displayPostOrder(){
	displayPostOrder(root);
}

void BinTree::displayPostOrder(DataNode * node){
	if(node){
		displayPreOrder(node->left);
		displayPreOrder(node->right);
		cout << "id: " << node->data.id << " , info: " << node->data.information << endl;
	}
}

void BinTree::displayInOrder(){
	displayInOrder(root);
}

void BinTree::displayInOrder(DataNode * node){
	if(node){
		displayInOrder(node->left);
		cout << "id: " << node->data.id << " , info: " << node->data.information << endl;
		displayInOrder(node->right);
	}
}



