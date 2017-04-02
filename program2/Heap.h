#ifndef HEAP_H
#define HEAP_H

#include "Player.h"
#include <vector>
#include <string>

using namespace std;
class Heap{
	public:
		Heap();
		Heap(string filename);
		Heap(const Heap &copy);
		void addPlayer(Player newPlayer);
		Player getPlayer();
		vector<Player> getArray();
		bool empty();
		unsigned int size();
		bool swap(int parentIndex, int childIndex);
		void siftUp(int index);
		bool siftDownDel(int index);
	private:
		vector<Player> arr;
};



#endif
