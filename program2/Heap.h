#ifndef HEAP_H
#define HEAP_H

#include <vector>

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
	private:
		vector<Player> arr;
};



#endif
