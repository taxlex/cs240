#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <time.h>

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
	//makes a vector temp that will be used to sort the values
	vector<int> temp;
	typename T::iterator iter;
	for(iter = values->begin(); iter != values->end(); iter++){
		temp.push_back(*iter);
	}
	clock_t t;
	t = clock();
	int tempA = 0;
	for(int y = 0; y<temp.size(); y++){
		for(int i = 0; i < temp.size()-1-y; i++){
			if(temp[i] > temp[i+1]){
				tempA=temp[i];
				temp[i]=temp[i+1];
				temp[i+1] = tempA;
			}
		}
	}
	t = clock() -t;
	cout<<"bubleSort() took: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
	//convert back to original type
	values->clear();
	vector<int>::iterator it;
	for(it = temp.begin(); it != temp.end(); it++){
		values->push_back(*it);
	}
	
}
template <class T>
void Sorter<T>::selectionSort(){
	//makes a vector temp that will be used to sort the values
	vector<int> temp;
	typename T::iterator iter;
	for(iter = values->begin(); iter != values->end(); iter++){
		temp.push_back(*iter);
	}
	clock_t t;
	t = clock();
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
	t = clock() -t;
	cout<<"selectionSort() took: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
	//convert back to original type
	values->clear();
	vector<int>::iterator it;
	for(it = temp.begin(); it != temp.end(); it++){
		values->push_back(*it);
	}
	
}


template <class T>
void Sorter<T>::insertionSort(){
	//makes a vector temp that will be used to sort the values
	vector<int> temp;
	typename T::iterator iter;
	for(iter = values->begin(); iter != values->end(); iter++){
		temp.push_back(*iter);
	}
	clock_t t;
	t = clock();
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
	t = clock() -t;
	cout<<"insertionSort() took: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
	//convert back to original type
	values->clear();
	vector<int>::iterator it;
	for(it = temp.begin(); it != temp.end(); it++){
		values->push_back(*it);
	}
	
}



#endif
