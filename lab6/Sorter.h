#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include <list>
#include <algorithm>
#include <stdlib.h>

using namespace std;

template <class T>
class Sorter{
	public:
		Sorter();
		void clear();
		unsigned int size();
		void insert(int);
		void shuffle();
		typename T::iterator operator[](int i);
	private:
		T * values;
};
template <class T>
Sorter<T>::Sorter(){
	values = new T;
}
template <class T>
void Sorter<T>::clear(){
	values->clear();
}
template <class T>
unsigned int Sorter<T>::size(){
	return values->size();
}
template <class T>
void Sorter<T>::insert(int i){
	values->push_back(i);
}
template <class T>
void Sorter<T>::shuffle(){
/*
	T::iterator iter;
	int runs = rand()%25;
	runs += 50;
	for(int i = 0; i < runs; i++){
		T temp.clear();
		unsigned int runs = rand()%values.size();
		for(iter = values.begin(); iter != values.end()-runs; iter++){
			temp.push_back(values[iter]);
		}
		for(; iter != values.end(); iter++){
			temp.push_front(values[iter]);
		}
		values = temp;
	}
*/
	random_shuffle(values->begin(), values->end(), values);
}
template <class T>
typename T::iterator operator[](int i){
	typename T::iterator iter = values.begin();
	for(int y = 0; iter != values->end() && y <= i; iter++){
		y++;
	} 
	return iter;
}





#endif
