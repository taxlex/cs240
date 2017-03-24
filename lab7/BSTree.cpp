#include <cstdlib>

#include <iostream>
#include <vector>
#include "BSTree.h"


BSTree::BSTree(){
	root = new Node(NULL);
}
BSTree::BSTree(const BSTree &old_tree){
	root = new Node(NULL);
	root->copyPreOrder(root, old_tree.root);
}
BSTree::~BSTree(){
	root->deleteTreePostOrder(root);
}
bool BSTree::empty(){
	if(root->hasVal) return false;
	return true;
}
bool BSTree::insert(int val){
	return root->insert(root, val);
}
bool BSTree::find(int val){
	return root->find(root, val);
}
void BSTree::sortedArray(vector<int> &list){
	root->sortedArrayInOrder(list, root);
}
bool BSTree::remove(int num){
	if(find(num) == false) return false;
	root->removePreOrder(root, num);
	return true;
}









BSTree::Node::Node(Node * aParent){
	hasVal = false;
	leftSubTree = NULL;
	rightSubTree = NULL;
	parent = aParent;
}

bool BSTree::Node::insert(Node * currNode, int val){
	if(currNode->hasVal == false){
		currNode->data = val; 
		currNode->hasVal = true;
		return true;
	}
	else if(currNode->data == val) return false;
	else if(val < currNode->data && currNode->leftSubTree == NULL){
		currNode->leftSubTree = new Node(currNode);
		return insert(currNode->leftSubTree, val);
	}
	else if(val < currNode->data){
		return insert(currNode->leftSubTree, val);
	}
	else if(val > currNode->data && currNode->rightSubTree == NULL){
		currNode->rightSubTree = new Node(currNode);
		return insert(currNode->rightSubTree, val);
	}
	else{
		return insert(currNode->rightSubTree, val);
	}
}
bool BSTree::Node::find(Node * currNode, int val){
	if(currNode->hasVal == false){
		return false;
	}
	else if(currNode->data == val) return true;
	else if(val < currNode->data && currNode->leftSubTree != NULL){
		return find(currNode->leftSubTree, val);
	}
	else if(val > currNode->data && currNode->rightSubTree != NULL){
		return find(currNode->rightSubTree, val);
	}
	else return false;
}
void BSTree::Node::copyPreOrder(Node * to, Node * from){
	to->data = from->data;
	to->hasVal = true;
	if(from->leftSubTree->hasVal){
		to->leftSubTree = new Node(to);
		copyPreOrder(to->leftSubTree,from->leftSubTree);
	}
	if(from->rightSubTree->hasVal){
		to->rightSubTree = new Node(to);
		copyPreOrder(to->rightSubTree, from->rightSubTree);
	}
}
void BSTree::Node::deleteTreePostOrder(Node * currNode){
	if(currNode->leftSubTree->hasVal){
		deleteTreePostOrder(currNode->leftSubTree);
	}
	if(currNode->rightSubTree->hasVal){
		deleteTreePostOrder(currNode->rightSubTree);
	}
	delete currNode;
}
void BSTree::Node::sortedArrayInOrder(vector<int> &list, Node * currNode){
	if(currNode->leftSubTree != NULL){
		sortedArrayInOrder(list,currNode->leftSubTree);
	}
	list.push_back(currNode->data);
	if(currNode->rightSubTree != NULL){
		sortedArrayInOrder(list,currNode->rightSubTree);
	}
}
void BSTree::Node::removePreOrder(Node * currNode, int num){
	if(num < currNode->data) removePreOrder(currNode->leftSubTree, num);
	else if(num > currNode->data) removePreOrder(currNode->rightSubTree, num);
	else{
		if(currNode->leftSubTree != NULL && currNode->rightSubTree != NULL){
			Node * temp = currNode->rightSubTree->minVal();
			if(currNode->parent->leftSubTree == currNode)currNode->parent->leftSubTree = temp;
			else if(currNode->parent->rightSubTree == currNode)currNode->parent->rightSubTree = temp; 
			if(currNode->rightSubTree != temp) temp->parent->leftSubTree = NULL;
			temp->parent = currNode->parent;
			temp->leftSubTree = currNode->leftSubTree;
			temp->leftSubTree->parent = temp;
			if(temp->rightSubTree == NULL && currNode->rightSubTree != temp){
				temp->rightSubTree = currNode->rightSubTree;
				temp->rightSubTree->parent = temp;
			}
			else if(currNode->rightSubTree != temp){
				Node * maxTemp = temp->rightSubTree->maxVal();
				maxTemp->rightSubTree = currNode->rightSubTree;
				currNode->rightSubTree->parent = maxTemp;
			}
		}
		else if(currNode->leftSubTree != NULL){
			if(currNode->parent->leftSubTree == currNode)currNode->parent->leftSubTree = currNode->leftSubTree;
			else if(currNode->parent->rightSubTree == currNode)currNode->parent->rightSubTree = currNode->leftSubTree;
			currNode->leftSubTree->parent = currNode->parent; 
		}
		else if(currNode->rightSubTree != NULL){
			if(currNode->parent->leftSubTree == currNode)currNode->parent->leftSubTree = currNode->rightSubTree;
			else if(currNode->parent->rightSubTree == currNode)currNode->parent->rightSubTree = currNode->rightSubTree;
			currNode->rightSubTree->parent = currNode->parent; 
		}
		else{
			if(currNode->parent->leftSubTree == currNode)currNode->parent->leftSubTree = NULL;
			else if(currNode->parent->rightSubTree == currNode)currNode->parent->rightSubTree = NULL;
		}
		delete currNode;
	}
}
BSTree::Node* BSTree::Node::minVal(){
	if(this->leftSubTree->data < this->data){
		return this->leftSubTree->minVal();
	}
	else return this;
}
BSTree::Node* BSTree::Node::maxVal(){
	cout<<"cp1"<<endl;
	if(this->rightSubTree->data > this->data){
		return this->rightSubTree->maxVal();
	}
	else return this;
}