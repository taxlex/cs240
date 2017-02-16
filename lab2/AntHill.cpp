#include "AntHill.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/*Ant constructors and functions-------------------------------------------------------------------------*/
Ant::Ant(void){
	id = -1;
	x = 0;
	y = 0;
}
Ant::Ant(int aId){
	id = aId;
	x = 0;
	y = 0;
}
void Ant::move(){
	int randXY = rand()%2;
	int randDist = rand()%2;
	if(randXY == 0){
		if(randDist == 0) x--;
		else if(randDist == 1) x++;
	}
	else if(randXY == 1){
		if(randDist == 0) y--;
		else if(randDist == 1) y++;
	}
}
int Ant::getID(){
	return id;
}
int Ant::getX(){
	return x;
}
int Ant::getY(){
	return y;
}
/*AntFarm constructor and functions----------------------------------------------------------------------*/
AntHill::AntHill(int aMax_ants){
	max_ants = aMax_ants;
	current_ants=0;
	next_id = 0;
	
}
bool AntHill::addAnt(){
	if(next_id < max_ants){
		ants[next_id] = Ant(next_id);
		current_ants++;
		next_id++;
		return true;
	}
	else return false;
}
Ant AntHill::getAnt(int antID){
	return ants[antID];
}
void AntHill::move(){
	for(int i = 0; i <= next_id; i++){
		ants[i].move();
	}
}
bool AntHill::changeMax(int aMax_ants){
	if(aMax_ants >=0 && aMax_ants <= 100){
		max_ants = aMax_ants;
		return true;
	}
	else return false;
}
void AntHill::printHillInfo(){
	for(int i = 0; i<= next_id; i++){
		cout<<"Ant#"<<i<<"["<<ants[i].getX()<<","<<ants[i].getY()<<"]\n";
	}
}
int AntHill::getCurrentNumAnts(){
	return current_ants;
}
int AntHill::getMaxAnts(){
	return max_ants;
}
