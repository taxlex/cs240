#include "Ant.h"
#include <iostream>
#include <cstdlib>

using namespace std;
//constructor takes an int for the id, up to caller to assure it is a unique id
Ant::Ant(int aId){
	id = aId;
	x = 0;
	y = 0;
	exp = 10;
}
//copy constructor note: id will not be unique
Ant::Ant(const Ant& anAnt){
	id = anAnt.id;
	x = anAnt.x;
	y = anAnt.y;
	exp = anAnt.exp;
}
//moves a single ant 1 unit, if the one unit would be out of the grid it doesn't move
void Ant::move(){
	int randXY = rand()%4;
	if(randXY == 0 && x<30){x++;}
	if(randXY == 1 && x>-30){x--;}
	if(randXY == 2 && y<30){y++;}
	if(randXY == 3 && y>-30){y--;}

}
//fight mechanic that takes exp into account
Ant * Ant::fight(Ant * enemy){
	int totExp = this->exp + enemy->exp;
	int randNum = rand()%totExp;
	if(randNum < this->exp){
		this->exp += enemy->exp;
		Ant * winner = this;
		return winner;
	}
	else{
		enemy->exp += this->exp;
		Ant * winner = enemy;
		return winner;
	}
}
