#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstddef>
#include "Ant.h"

using namespace std;
class Node{
	public:
		Node(Ant *);
		Node * next;
		Ant * currAnt;
};
class LinkedList{
	public:
		LinkedList();
		LinkedList(const LinkedList&);
		~LinkedList();
		void addAnt();
		void deleteAnt(int);
		Ant * findAnt(int);
		void printLinkedList();
		LinkedList& operator<<(Ant *);
		void moveAll();
		int attacked(int);
		int antOneOnOneFindFood();
		//LinkedList& operator<<(Ant);
	private:
		Node *head;
		int nextID;
};
#endif
