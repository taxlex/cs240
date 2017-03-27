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
	if(root->hasVal){ 
		root->sortedArrayInOrder(list, root);
	}
}
bool BSTree::remove(int num){
	if(find(num) == false) return false;
	root->removePreOrder(root, num);
	return true;
}
void BSTree::printBST(){
	root->printNode(root,0);
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
	if(from->leftSubTree != NULL){
		to->leftSubTree = new Node(to);
		copyPreOrder(to->leftSubTree,from->leftSubTree);
	}
	if(from->rightSubTree != NULL){
		to->rightSubTree = new Node(to);
		copyPreOrder(to->rightSubTree, from->rightSubTree);
	}
}
void BSTree::Node::deleteTreePostOrder(Node * currNode){
	if(currNode->leftSubTree != NULL){
		deleteTreePostOrder(currNode->leftSubTree);
	}
	if(currNode->rightSubTree != NULL){
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
			currNode->data = currNode->rightSubTree->minVal()->data;
			currNode->removePreOrder(currNode->rightSubTree, currNode->rightSubTree->minVal()->data);

		}
		else if(currNode->leftSubTree != NULL){
			Node * temp = currNode->leftSubTree;
			currNode->data = temp->data;
			currNode->leftSubTree = temp->leftSubTree;
			currNode->rightSubTree = temp->rightSubTree;
			if(temp->rightSubTree != NULL){
				temp->rightSubTree->parent = currNode;
			}
			if(temp->leftSubTree != NULL){
				temp->leftSubTree->parent = currNode;
			}
			delete temp;
		}
		else if(currNode->rightSubTree != NULL){
			Node * temp = currNode->rightSubTree;
			currNode->data = temp->data;
			currNode->leftSubTree = temp->leftSubTree;
			currNode->rightSubTree = temp->rightSubTree;
			if(temp->rightSubTree != NULL){
				temp->rightSubTree->parent = currNode;
			}
			if(temp->leftSubTree != NULL){
				temp->leftSubTree->parent = currNode;
			}
			delete temp;

		}
		else{
			if(currNode->parent != NULL){
				if(currNode->parent->leftSubTree == currNode)currNode->parent->leftSubTree = NULL;
				else if(currNode->parent->rightSubTree == currNode)currNode->parent->rightSubTree = NULL;
				delete currNode;
			}
			else{
				currNode->hasVal = false;
			} 
		}
	}
}
BSTree::Node* BSTree::Node::minVal(){
	if(this->leftSubTree != NULL){
		return this->leftSubTree->minVal();
	}
	else return this;
}
BSTree::Node* BSTree::Node::maxVal(){	
	if(this->rightSubTree != NULL){
		return this->rightSubTree->maxVal();
	}
	else return this;
}
void  BSTree::Node::printNode(Node * currNode, int level){
	if(currNode->rightSubTree != NULL){
		printNode(currNode->rightSubTree, level+1);
	}
	string str;
	if(currNode->rightSubTree != NULL){
		for(int i =0; i < level; i++){
			cout<<"    ";
		}
		cout<<"   /"<<endl;
	}
	for(int i =0; i <level; i++){
		if(i+1 == level){
			str += "   +";
		}
		else str += "    ";
	}
	cout<<str;
	cout<<currNode->data<<endl;
	if(currNode->leftSubTree != NULL){
		for(int i =0; i < level; i++){
			cout<<"    ";
		}
		cout<<"   \\"<<endl;
	}
	if(currNode->leftSubTree != NULL){
		printNode(currNode->leftSubTree, level+1);
	}
}