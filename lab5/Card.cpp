#include "Card.h"
#include <iostream>
using namespace std;

Card::Card(int suit, int value){
	if(suit > 0 && suit < 5) this->suit = suit;
	else cout<<"not in suit range"<<endl;
	if(value > 1 && value < 15) this->value = value;
	else cout<<"not in value range"<<endl;
}
bool Card::operator==(const Card &other){
	if(this->value != other.value) return false;
	if(this->suit != other.suit) return false;
	return true;
}
