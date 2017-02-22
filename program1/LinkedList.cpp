#include "LinkedList.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
Node::Node(Ant * aCurrAnt){
	currAnt = aCurrAnt;
	next = NULL;
}
LinkedList::LinkedList(){
	head = NULL;
	nextID = 0;
}
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
}
LinkedList::~LinkedList(){
	Node* current = head;
	while( current != NULL ) {
		Node* next = current->next;
		delete current->currAnt;
		delete current;
		current = next;
	}
	head = NULL;
}
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
}
void LinkedList::deleteAnt(int id){
	Node * findID = head;
	//deals with deleting only element
	if(head->currAnt->getID() == id && head->next == NULL){
		delete findID->currAnt;
		delete findID;
		head = NULL;
	}
	//deals with deleting the first element
	else if(head->currAnt->getID() == id){
		head = head->next;
		delete findID->currAnt;
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
		delete findID->currAnt;
		delete findID;
	}
	
}
Ant * LinkedList::findAnt(int id){
	Node * findID = head;
	if(findID == NULL){return 0;}
	while(findID != NULL){
		findID = findID->next;
		if(findID->currAnt->getID() == id){return findID->currAnt;}
	}
	return NULL;
}
void LinkedList::printLinkedList(){
	Node * temp = head;
	while(temp != NULL){
		cout << temp->currAnt->getID() << " ";
		temp = temp->next;
	}
	cout<< endl;
}
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
}
void LinkedList::moveAll(){
	Node * temp = head;
	while(temp != NULL){
		temp->currAnt->move();
		temp = temp->next;
	}
}
/*****
Defenders of the ant hill are those ants that are within 15 units from the 0,0 coordinate, if there are more defenders than attackers then nothing happens, if the defenders are defeated they all die note: only those within 15 units from the center are killed
*****/
int LinkedList::attacked(int attackers){
	int defenders = 0;
	int antHillAntsKilled =0;
	Node * temp = head;
	while(temp != NULL){
		if(temp->currAnt->getX() >= -15 && temp->currAnt->getX() <= 15 && temp->currAnt->getY() >= -15 && temp->currAnt->getY() <= 15 ){
			defenders++;
		}
		temp = temp->next;
	}
	if(defenders > attackers)antHillAntsKilled = 0;
	else{
		Node * tempNext = head->next;
		temp = head;
		while(temp != NULL){
			tempNext = temp->next;
			if(temp->currAnt->getX() >= -15 && temp->currAnt->getX() <= 15 && temp->currAnt->getY() >= -15 && temp->currAnt->getY() <= 15 ){
			antHillAntsKilled++;
			deleteAnt(temp->currAnt->getID());
			}
			temp = tempNext;
		}
	}
	return antHillAntsKilled;
}
/*****
Each ant in the linked list has a chance of encountering a rival ant which may kill them, if an ant does not encounter a rival ant it has a chance of finding food, in order to return the amount of food found and ants killed by rival ants the function takes an int * as an argument
*****/
int LinkedList::antOneOnOneFindFood(int *antsKilled){
	int food = 0;
	int antsKilledOneOnOne = 0;
	Node * temp = head;
	Node * tempNext = head->next;
	while(temp != NULL){
		tempNext = temp->next;
		if(rand()%5 == 0){
			if(rand()%2 == 0){
				antsKilledOneOnOne++;
				deleteAnt(temp->currAnt->getID());
			}
		}
		else{
			if(rand()%3 == 0){
				food++;
			}
		}
		temp = tempNext;
	}
	*antsKilled = antsKilledOneOnOne;
	ofstream log;
	log.open("anthill.log", ios_base::app);
	if(antsKilledOneOnOne == 0){
		log<<"no ants lost a one on one fight this turn"<<endl;
	}
	if(antsKilledOneOnOne == 1){
		log<<antsKilledOneOnOne<<" ant picked a fight he couldn't win this turn"<<endl;
	}
	if(antsKilledOneOnOne > 1){
		log<<antsKilledOneOnOne<<" ants picked a fight they couldn't win this turn"<<endl;
	}
	
	if(food == 0){
		log<<"no ants found food this turn"<<endl;
	}
	if(food == 1){
		log<<food<<" ant found food this turn"<<endl;
	}
	if(food > 1){
		log<<food<<" ants found food this turn"<<endl;
	}
	log.close();
	return food;
}
