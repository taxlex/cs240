#include "Table.h"
#include <vector>



using namespace std;
Table::Table(int num_seats, int ante){
	num_players = num_seats;
	min_ante = ante;
}
bool Table::emptySeat(){
	if(playing.size() >= num_players)return false;
	return true;
}
vector<Player> Table::playRound(){
	theDeck = new Deck();
	theDeck->shuffle();
	for(int i = 0; i < num_players; i++){
		playing[i].bet(min_ante);
		playing[i].hand = theDeck->draw();
	}
	Player winner = playing[0];
	int winnerIndex = 0;
	for(int i = 1; i < num_players; i++){
		if(playing[i].hand.getValue() > winner.hand.getValue()){
			winner = playing[i];
			winnerIndex = i;
		}
	}
	playing.erase(playing.begin() + winnerIndex);
	vector<Player> ret = playing;
	playing.clear();
	winner.collectWinnings(num_players*min_ante);
	playing.push_back(winner);
	delete theDeck;
	return ret;

}
void Table::addPlayer(Player p){
	if(playing.size() < num_players && p.getBudget() >= min_ante){
		playing.push_back(p);
	}
}
void Table::printWinner(){
	cout<<playing[0].getName()<<endl;
}