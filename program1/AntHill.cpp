#include "AntHill.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
AntHill::AntHill(){
	ants = new LinkedList();
	current_ants=0;
	antFood = 0;
	addAnt();
	addAnt();
	addAnt();
	
}
AntHill::~AntHill(){
	for(int i=0; i< current_ants; i++){
		delete ants[i];
	}
	delete[] ants;
}
int AntHill::addAnt(){
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
	return ants[current_ants -1]->getID();
}
bool AntHill::removeAnt(int antID){
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
}
Ant * AntHill::getAnt(int antID){
	for(int i = 0; i< current_ants; i++){
		if(ants[i]->getID()== antID){
			return ants[i];
		}
	}
	return NULL;
}
void AntHill::move(){
	for(int i = 0; i < current_ants; i++){
		ants[i]->move();
	}
}
void AntHill::printHillInfo(){
	for(int i = 0; i < current_ants; i++){
		cout<<"Ant#"<<i<<"["<<ants[i]->getX()<<","<<ants[i]->getY()<<"]\n";
	}
}
void turn(){
	
}
void writeToLog(string){
	ofstream logfile;
	logfile.open("anthill.log");
	logfile<< string;
	logfile.close();
}
