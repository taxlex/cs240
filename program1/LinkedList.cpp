#include "LinkedList.h"
#include <iostream>
#include <cstdlib>

using namespace std;
Node::Node(Ant * aCurrAnt){
	currAnt = aCurrAnt;
	next = NULL;
};
LinkedList::LinkedList(){
	head = NULL;
	nextID = 0;
};
LinkedList::LinkedList(const LinkedList& Ll){
	Node* tempLl = Ll.head;
	this->head = new Node(Ll.head->currAnt);
	Node* temp = this->head;
	tempLl = tempLl->next;
	while(tempLl != NULL){
		temp->next = new Node(tempLl->currAnt);
		temp = temp->next;
		tempLl = tempLl->next;
	}
};
LinkedList::~LinkedList(){
	Node* current = head;
	while( current != NULL ) {
		Node* next = current->next;
		delete current->currAnt;
		delete current;
		current = next;
	}
	head = NULL;
};
void LinkedList::addAnt(){
	Ant * newAnt = new Ant(nextID);
	nextID++;
	Node * newNode = new Node(newAnt);
	
	Node * findEnd = head;
	
	if(findEnd != NULL){
		while(findEnd->next != NULL){
			findEnd = findEnd->next;
		}
		findEnd->next = newNode;
	}
	else{
		head = newNode;
	}
};
void LinkedList::deleteAnt(int id){
	Node * findID = head;
	//deals with deleting the first element
	if(head->currAnt->getID() == id){
		head = head->next;
		delete findID;
	}
	else{
		//if the linked list is empy it returns ends
		if(findID == NULL){return;}
		//variable to keep track of the previous node
		Node * prev = NULL;
		//goes through each node until it reaches the correct ant or the end of list
		while(findID != NULL){
			prev = findID;
			findID = findID->next;
			if(findID->currAnt->getID() == id){break;}
		}
		//links together the gap that wll be made after deleting an ant
		prev->next = findID->next;
		//deletes the ant
		delete findID;
	}
	
};
Ant * LinkedList::findAnt(int id){
	Node * findID = head;
	if(findID == NULL){return 0;}
	while(findID != NULL){
		findID = findID->next;
		if(findID->currAnt->getID() == id){return findID->currAnt;}
	}
	return NULL;
};
void LinkedList::printLinkedList(){
	Node * temp = head;
	while(temp != NULL){
		cout << temp->currAnt->getID() << " ";
		temp = temp->next;
	}
	cout<< endl;
};
LinkedList& LinkedList::operator<<(Ant * anAnt){
	Node * newNode = new Node(anAnt);
	
	Node * findEnd = head;
	
	if(findEnd != NULL){
		while(findEnd->next != NULL){
			findEnd = findEnd->next;
		}
		findEnd->next = newNode;
	}
	else{
		head = newNode;
	}
};
void LinkedList::moveAll(){
	Node * temp = head;
	while(temp != NULL){
		temp->currAnt->move();
		temp = temp->next;
	}
};
int LinkedList::attacked(int attackers){
	int defenders = 0;
	int antHillAntsKilled;
	Node * temp = head;
	while(temp != NULL){
		if(temp->currAnt->getX() >= -25 && temp->currAnt->getX() <= 25 && temp->currAnt->getY() >= -25 && temp->currAnt->getY() <= 25 ){
			defenders++;
		}
		temp = temp->next;
	}
	if(defenders > attackers)antHillAntsKilled = 0;
	else{
		while(temp != NULL){
			if(temp->currAnt->getX() >= -25 && temp->currAnt->getX() <= 25 && temp->currAnt->getY() >= -25 && temp->currAnt->getY() <= 25 ){
			antHillAntsKilled++;
			deleteAnt(temp->currAnt->getID());
			}
			temp = temp->next;
		}
	}
	return antHillAntsKilled;
};
int LinkedList::antOneOnOneFindFood(){
	int food = 0;
	Node * temp = head;
	while(temp != NULL){
		if(rand()%5 == 0){
			if(rand()%2 == 0){
				deleteAnt(temp->currAnt->getID());
			}
			else food++;
		}
		else{
			if(rand()%5 == 0){
				food++;
			}
		}
		temp = temp->next;
	}
	return food;
};
