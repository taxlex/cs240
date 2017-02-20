#include "AntHill.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;
AntHill::AntHill(){
	ants = new LinkedList();
	currentAnts=0;
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
	currentAnts++;
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
void AntHill::printHillInfo(){
	/*for(int i = 0; i < current_ants; i++){
		cout<<"Ant#"<<i<<"["<<ants[i]->getX()<<","<<ants[i]->getY()<<"]\n";
	}
	*/
}
void AntHill::turn(){
	ofstream log;
	log.open("anthill.log");
	log << "hello\n";
	log.close();
	int antsKilledInAttack = 0;
	ants->moveAll();
	if(rand()%5 == 0){
		int attackers = 1 + rand()%currentAnts;
		antsKilledInAttack = ants->attacked(attackers);
		cout << "The anthill was attacked! ";
		if(antsKilledInAttack > 0){
			cout << antsKilledInAttack;
			cout << "lost there lives defending the hill\n";
		}
	}
	antFood += ants->antOneOnOneFindFood();
	for(antFood; antFood>=0; antFood--){
		addAnt();
	}
}
