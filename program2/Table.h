#ifndef TABLE_H
#define TABLE_H

#include <vector>

using namespace std;
class Table{
	public:
		Table(int num_seats, int ante);
		bool emptySeat();
		vector<Player> playRound();
		void addPlayer(Player p);
		void printWinner();
	private:
};



#endif
