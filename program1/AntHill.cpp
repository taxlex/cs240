#include "AntHill.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
//constructor that deletes if it exists to write to a new log, starts with 3 ants
using namespace std;
AntHill::AntHill(){
	remove("anthill.log");
	ants = new LinkedList();
	currentAnts=0;
	antFood = 0;
	turnNum = 0;
	addAnt();
	addAnt();
	addAnt();
	
}
AntHill::~AntHill(){
	delete ants;
}
//delegates adding ants to the linked list and updates the population of ants
void AntHill::addAnt(){
	ants->addAnt();
	currentAnts++;
}
//delegates to linked list
bool AntHill::removeAnt(int antID){
	ants->deleteAnt(antID);
}
//delegates to linked list
Ant * AntHill::getAnt(int antID){
	return ants->findAnt(antID);
}
/*****
Moves all the ants, the anthill has a chance to be attacked, each ant has a chance to find and fight a rival ant, if he doesn't find another ant he has a chance to find food, food is used to make more ants, information is written to the anthill.log file
*****/
void AntHill::turn(){
	ofstream log;
	log.open("anthill.log", ios_base::app);
	log<<"Turn: "<<turnNum<<endl;
	
	int antsKilledInAttack = 0;
	ants->moveAll();
	if(rand()%5 == 0){
		int attackers = 1 + rand()%currentAnts;
		antsKilledInAttack = ants->attacked(attackers);
		log<<"The anthill was attacked! ";
		if(antsKilledInAttack > 0){
			log<<antsKilledInAttack<<" ants lost there lives defending the hill"<<endl;
			currentAnts -= antsKilledInAttack;
		}
		else{
			log<<"no defending ants lost there lives"<<endl;
		}
	}
	if(currentAnts > 0){
		int antsKilled = 0;
		antFood += ants->antOneOnOneFindFood(&antsKilled);
		for(antFood; antFood>0; antFood--){
			addAnt();
		}
		currentAnts -= antsKilled;
	}
	log<<"The total number of ants is now: "<<currentAnts<<endl<<endl;
	log.close();
	turnNum++;
}
