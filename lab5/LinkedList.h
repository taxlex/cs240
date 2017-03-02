#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

template <class T>
class Node{
	public:
		Node(T *);
		Node * nextNode;
		T * currentData;
		template<class T2> friend class Queue;
};
template <class T>
Node<T>::Node(T * currentData){
	this->currentData = currentData;
	this->nextNode = NULL;
};
template <class T>
class LinkedList{
	public:
		LinkedList();
		LinkedList(const LinkedList<T>&);
		~LinkedList();
		void insert(T);
		T& read();
		bool empty();
		bool remove(T&);
		template<class T2> friend class Queue;
	private:
		Node<T> *head;
		Node<T> *iterator;
};
template <class T>
LinkedList<T>::LinkedList(){
	head = NULL;
	iterator = head;
}
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& sll){
	this->iterator = sll.iterator;
	Node<T>* tempSll = sll.head;
	this->head = new Node<T>(sll.head->currentData);
	Node<T>* temp = this->head;
	tempSll = tempSll->next;
	while(tempSll != NULL){
		temp->next = new Node<T>(tempSll->currentData);
		temp = temp->next;
		tempSll = tempSll->next;
	}
}
template <class T>
LinkedList<T>::~LinkedList(){
	Node<T>* current = head;
	while(current != NULL){
		Node<T>* next = current->nextNode;
		delete current->currentData;
		delete current;
		current = next;
	}
	head = NULL;
}
template <class T>
void LinkedList<T>::insert(T data){
	Node<T> * newNode = new Node<T>(&data);
	Node<T> * findEnd = head;
	if(findEnd != NULL){
		while(findEnd->nextNode != NULL){
			findEnd = findEnd->nextNode;
		}
		findEnd->nextNode = newNode;
	}
	else{
		head = newNode;
	}
}
template <class T>
T& LinkedList<T>::read(){
	if(iterator == NULL && head != NULL){
		iterator = head;
	}
	if(iterator == NULL && head == NULL){
		cout<<"List is empty"<<endl;
	}
	T &temp = *iterator->currentData;
	iterator = iterator->nextNode;
	return temp;
}
template <class T>
bool LinkedList<T>::empty(){
	if(head == NULL) return true;
	else return false;
}
template <class T>
bool LinkedList<T>::remove(T& data){
	Node<T> * findData = head;
	//deals with deleting only element
	if(head->currentData == &data && head->nextNode == NULL){
		delete findData->currentData;
		delete findData;
		head = NULL;
		return true;
	}
	//deals with deleting the first element
	else if(head->currentData == &data){
		head = head->nextNode;
		delete findData->currentData;
		delete findData;
	}
	else{
		//if the LinkedList is empty it returns false
		if(findData == NULL) return false;
		//variable to keep track of previous node
		Node<T> * previous = NULL;
		//goes through each node until it reaches the correct data or end
		while(findData != NULL){
			previous = findData;
			findData = findData->nextNode;
			if(findData->currentData == &data) break;
		}
		if(findData != NULL){
			previous->nextNode = findData->nextNode;
			delete findData->currentData;
			delete findData;
			return true;
		} 
		else return false;
	}
}









#endif
