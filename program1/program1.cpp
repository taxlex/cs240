#include <iostream>
#include "LinkedList.h"

int main(){
	LinkedList * a = new LinkedList();
	for(int i =0; i < 20 ; i++){
		a->addAnt();
		
	}
	cout<<"checkpoint 1"<<endl;
	LinkedList* b = new LinkedList(*a);
	a->deleteAnt(0);
	a->printLinkedList();
	b->printLinkedList();
	Ant * an = new Ant(55);
	Ant * bn = new Ant(66);
	*b<<an<<bn;
	b->printLinkedList();
	delete a;
	delete b;


return 0;
}
