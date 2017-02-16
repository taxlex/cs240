#include "Ant.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Ant::Ant(int aId){
	id = aId;
	x = 0;
	y = 0;
	exp = 10;
}
void Ant::move(){
	int randXY = rand()%4;
	if(randXY == 0){x++;}
	if(randXY == 1){x--;}
	if(randXY == 2){y++;}
	if(randXY == 3){y--;}

}
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
