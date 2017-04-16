#include "Player.h"
#include "Card.h"
using namespace std;
Player::Player(string aName, int aBudget){
	name = aName;
	budget = aBudget;
}
string Player::getName(){
	return name;
}
int Player::getBudget(){
	return budget;
}
bool Player::bet(int amount){
	budget -= amount;
}
void Player::collectWinnings(int amount){
	budget += amount;
}
