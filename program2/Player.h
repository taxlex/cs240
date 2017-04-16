#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

#include "Card.h"

using namespace std;
class Player{
	public:
		Player(string aName, int aBudget);
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
