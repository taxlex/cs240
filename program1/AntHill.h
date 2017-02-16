#ifndef ANTHILL_H
#define ANTHILL_H
#include "Ant.h"
#include "LinkedList.h"

using namespace std;
class AntHill{
	public:
		AntHill();
		~AntHill();
		int addAnt();
		bool removeAnt(int);
		Ant * getAnt(int);
		void printHillInfo();
		int getCurrentNumAnts(){return current_ants;}
		void move();
		void turn();
		void writeToLog(string);
	private:
		int current_ants;
		LinkedList ants;
		int antFood;
};

#endif
