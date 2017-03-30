#ifndef BSTREE_H
#define BSTREE_H

#include <vector>

using namespace std;
class Player{
	public:
		Player(String name, int budget);
		Card hand;
		string getName();
		int getBudget();
		bool bet(int amount);
		void collectWinnings(int amount);
	private:
		int budget;
};



#endif
