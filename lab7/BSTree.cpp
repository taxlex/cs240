#include <cstdlib>

#include <iostream>
#include "BSTree.h"


BSTree::BSTree(){
	root = new Node(NULL);
}
BSTree::BSTree(const BSTree &old_tree){
	root = new Node(NULL);
	root->copyPostOrder(root, old_tree.root);
}
BSTree::~BSTree(){
	delete root;
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
void BSTree::Node::copyPostOrder(Node * to, Node * from){
	to->data = from->data;
	to->hasVal = true;
	if(from->leftSubTree->hasVal){
		to->leftSubTree = new Node(to);
		copyPostOrder(to->leftSubTree,from->leftSubTree);
	}
	if(from->rightSubTree->hasVal){
		to->rightSubTree = new Node(to);
		copyPostOrder(to->rightSubTree, from->rightSubTree);
	}
}