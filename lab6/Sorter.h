#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <iostream>

using namespace std;

template <class T>
class Sorter{
	public:
		Sorter();
		~Sorter();
		void clear();
		unsigned int size();
		void insert(int);
		void shuffle();
		typename T::iterator operator[](int i);
		void bubbleSort();
		void selectionSort();
		void insertionSort();
	private:
		T * values;
};
template <class T>
Sorter<T>::Sorter(){
	values = new T;
}
template <class T>
Sorter<T>::~Sorter(){
	delete values;
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
		for(iter = values->begin(); iter != values->end() && y < i; iter++){
			y++;
		}
		return iter;
	}
}
template <class T>
void Sorter<T>::bubbleSort(){
	vector<int> temp;
	typename T::iterator iter;
	for(iter = values->begin(); iter != values->end(); iter++){
		temp.push_back(*iter);
	}
	int tempA = 0;
	for(int y = 0; y<temp.size(); y++){
		for(int i = 0; i < temp.size()-1; i++){
			if(temp[i] > temp[i+1]){
				tempA=temp[i];
				temp[i]=temp[i+1];
				temp[i+1] = tempA;
			}
		}
	}
	values->clear();
	vector<int>::iterator it;
	for(it = temp.begin(); it != temp.end(); it++){
		values->push_back(*it);
	}
	/*
	int tempA;
	for(int y = 0; y<values->size(); y++){
		for(int i = 0; i < values->size()-1; i++){
			if(values[i] > values[i+1]){
				tempA=values[i];
				values->insert(i,values[i+1]);
				values->insert(i+1,tempA);
			}
		}
	}
	*/
	
}
template <class T>
void Sorter<T>::selectionSort(){
	vector<int> temp;
	typename T::iterator iter;
	for(iter = values->begin(); iter != values->end(); iter++){
		temp.push_back(*iter);
	}
	int minIndex = 0;
	int sortedIndex = 0;
	int tempVal = 0;
	for(int y = 0; y<temp.size(); y++){
		minIndex = y;
		for(int i = y; i < temp.size(); i++){
			if(temp[i] < temp[minIndex]){
				minIndex = i;
			}
		}
		tempVal = temp[minIndex];
		temp[minIndex] = temp[sortedIndex];
		temp[sortedIndex] = tempVal;
		sortedIndex++;
	}
	values->clear();
	vector<int>::iterator it;
	for(it = temp.begin(); it != temp.end(); it++){
		values->push_back(*it);
	}
	
}


template <class T>
void Sorter<T>::insertionSort(){
	vector<int> temp;
	typename T::iterator iter;
	for(iter = values->begin(); iter != values->end(); iter++){
		temp.push_back(*iter);
	}
	int sortedIndex;
	int tempVal;
	for(int i = 1; i < temp.size(); i++){
		sortedIndex = i;
		tempVal = temp[i];

		while(sortedIndex > 0 && temp[sortedIndex-1] > tempVal){
			temp[sortedIndex] = temp[sortedIndex -1];
			sortedIndex--;
		}
		temp[sortedIndex] = tempVal;
	}
	values->clear();
	vector<int>::iterator it;
	for(it = temp.begin(); it != temp.end(); it++){
		values->push_back(*it);
	}
	
}



#endif
