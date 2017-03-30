#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

using namespace std;
class Player{
	public:
		Player(String aName, int aBudget);
		Card hand;
		string getName();
		int getBudget();
		bool bet(int amount);
		void collectWinnings(int amount);
	private:
		int budget;
		string name;
};



#endif
