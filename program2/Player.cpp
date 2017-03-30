#include "Player.h"

using namespace std;

Player::Player(String aName, int aBudget){
	name = aName;
	budget = aBudeget;
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
