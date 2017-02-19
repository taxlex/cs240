#include "AntHill.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
AntHill::AntHill(){
	ants = new LinkedList();
	current_ants=0;
	antFood = 0;
	ants->addAnt();
	ants->addAnt();
	ants->addAnt();
	
}
AntHill::~AntHill(){
	delete ants;
	/*for(int i=0; i< current_ants; i++){
		delete ants[i];
	}
	delete[] ants;
	*/
}
void AntHill::addAnt(){
/*
	if(ants == NULL){
		ants = new Ant*[1];
	}
	else{
		Ant ** temp = new Ant*[current_ants +1];
		memcpy(temp, ants, current_ants*sizeof(Ant*));
		delete[] ants;
		ants = temp;
	}
	ants[current_ants] = new Ant(next_id);
	*/
	ants->addAnt();
	current_ants++;
}
bool AntHill::removeAnt(int antID){
	ants->deleteAnt(antID);
/*
	if(ants == NULL){
		return false;
	}
	else{
		bool inHill = false;
		int position;
		for(int i = 0; i< current_ants; i++){
			if(ants[i]->getID()== antID){
				inHill = true;
				position = i;
				break;
			}
		}
		if(inHill == false){
			return false;
		}
		else if(inHill == true && current_ants == 1){
			delete[] ants;
			ants = NULL;
			return true;
		}
		else{
			Ant ** temp = new Ant*[current_ants - 1];
			memcpy(temp, ants, (position)*sizeof(Ant*));
			memcpy(temp+position, ants+position+1, (current_ants-position-1)*sizeof(Ant*));
			delete ants[position];
			delete[] ants;
			ants = temp;
			current_ants--;
			return true;
		}
	}
	*/
}
Ant * AntHill::getAnt(int antID){
	return ants->findAnt(antID);
	/*
	for(int i = 0; i< current_ants; i++){
		if(ants[i]->getID()== antID){
			return ants[i];
		}
	}
	return NULL;
	*/
}
void AntHill::move(){
	ants->moveAll();
/*
	for(int i = 0; i < current_ants; i++){
		ants[i]->move();
	}
	*/
}
void AntHill::printHillInfo(){
	/*for(int i = 0; i < current_ants; i++){
		cout<<"Ant#"<<i<<"["<<ants[i]->getX()<<","<<ants[i]->getY()<<"]\n";
	}
	*/
}
void turn(){
	/*move();
	if(rand()%5 == 0){
		//antHillAttacked();
	}
	*/
}
