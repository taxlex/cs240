#include <vector>
#include "Heap.h"

using namespace std;

Heap::Heap(){
	arr.clear();
}
void Heap::addPlayer(Player newPlayer){
	arr.push_back(newPlayer);
	siftUp((arr.size()-1)/2, arr.size()-1);
}
void siftUp(int parentIndex, int childIndex){
	if(arr[childIndex] > arr[parentIndex]){
		swap(parentIndex, childIndex);
		if(parentIndex > 0){
			siftUp((parentIndex-1)/2, parentIndex);
		}
	}
}

bool Heap::swap(int parentIndex, int childIndex){
	if(parentIndex < arr.size() && childIndex < arr.size()){
		int temp = arr[parentIndex];
		arr[parentIndex] = arr[childIndex];
		arr[childIndex] = temp;
		return true;
	}
	return false;
}
