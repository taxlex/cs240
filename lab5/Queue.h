#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "LinkedList.h"

using namespace std;

template <class T>
class Queue{
	public:
		Queue();
		~Queue();
		bool enqueue(T data);
		T dequeue();
		T peek();
		bool empty();
		void clear();
	private:
		int tot;
		LinkedList<T> * list;
};
template <class T>
Queue<T>::Queue(){
	list = new LinkedList<T>();
	tot = 0;
}
template <class T>
Queue<T>::~Queue(){
	clear();
	delete list;
	delete tot;
}
template <class T>
bool Queue<T>::enqueue(T data){
	list->insert(data);
	tot++;
	return true;
}
template <class T>
T Queue<T>::dequeue(){
	T temp = *list->head->currentData;
	list->remove(temp);
	return temp;
}
template <class T>
T Queue<T>::peek(){
	return *list->head->currentData;
}
template <class T>
bool Queue<T>::empty(){
	return list->empty();
}
template <class T>
void Queue<T>::clear(){
	while(tot !=0){
		T temp = dequeue();
		delete T;
		tot--;
	}
}








#endif
