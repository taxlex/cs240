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
	vector<int> temp;
	typename T::iterator iter;
	for(iter = values->begin(); iter != values->end(); iter++){
		temp.push_back(*iter);
	}
	random_shuffle(temp.begin(),temp.end());
	values->clear();
	vector<int>::iterator it;
	for(it = temp.begin(); it != temp.end(); it++){
		values->push_back(*it);
	}
}
template <class T>
typename T::iterator Sorter<T>::operator[](int i){
	if(i<= values->size()){
		typename T::iterator iter;
		int y = 0;
		for(iter = values->begin(); iter != values->end() && y < i+1; iter++){
			y++;
		}
		return iter;
	}
}





#endif
