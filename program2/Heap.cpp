#include <vector>
#include "Heap.h"

using namespace std;

Heap::Heap(){
	arr.clear();
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
bool Heap::siftDownDel(int index){
	if(index >= arr.size()) return false;
	if(index*2 +2 < arr.size()){
		if(arr[index*2 + 1].getBudget() > arr[index*2 +2].getBudget()){
			swap(index, index*2 +1);
			return siftDownDel(index*2 +1);
		}
		else{
			swap(index, index*2 + 2);
			return siftDownDel(index*2 + 2);
		}
	}
	else if(index*2 + 1 < arr.size()){
		swap(index, index*2 + 1);
		return siftDownDel(index*2 + 1);
	}
	else{
		arr.pop_back();
		return true;
	}
}
Player Heap::getPlayer(){
	Player temp = arr[0];
	siftDownDel(0);
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
