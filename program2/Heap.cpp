#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Heap.h"


using namespace std;

Heap::Heap(){
	arr.clear();
}
Heap::Heap(string filename){
	string name;
	string aBudget;
	int budget;
	ifstream input(filename.c_str());
	if(input){
		while(!input.eof()){
			getline(input,name);
			getline(input,aBudget);
			budget = strtol(aBudget.c_str(), NULL, 10);
			Player temp = Player(name,budget);
			addPlayer(temp);
		}
	}
}
void Heap::addPlayer(Player newPlayer){
	arr.push_back(newPlayer);
	siftUp(arr.size()-1);
}
void Heap::siftUp(int index){
	if(arr[index].getBudget() > arr[(index-1)/2].getBudget()){
		swap((index-1)/2, index);
		if((index-1)/2 > 0){
			siftUp((index-1)/2);
		}
	}
}
bool Heap::siftDown(int index){
	if(index >= arr.size()) return false;
	if(index*2 +2 < arr.size()){
		if(arr[index*2 + 1].getBudget() > arr[index*2 +2].getBudget() && arr[index*2 + 1].getBudget() > arr[index].getBudget()){
			swap(index, index*2 +1);
			return siftDown(index*2 +1);
		}
		else if(arr[index*2 + 2].getBudget() > arr[index].getBudget()){
			swap(index, index*2 + 2);
			return siftDown(index*2 + 2);
		}
	}
	else if(index*2 + 1 < arr.size() && arr[index*2 + 1].getBudget() > arr[index].getBudget()){
		swap(index, index*2 + 1);
		return siftDown(index*2 + 1);
	}
	else{
		return true;
	}
}
Player Heap::getPlayer(){
	Player temp = arr[0];
	swap(0, arr.size() -1);
	arr.pop_back();
	siftDown(0);
	return temp;
}
vector<Player> Heap::getArray(){
	return arr;
}
bool Heap::empty(){
	return arr.empty();
}
unsigned int Heap::size(){
	return arr.size();
}
bool Heap::swap(int parentIndex, int childIndex){
	if(parentIndex < arr.size() && childIndex < arr.size()){
		Player temp = arr[parentIndex];
		arr[parentIndex] = arr[childIndex];
		arr[childIndex] = temp;
		return true;
	}
	return false;
}
