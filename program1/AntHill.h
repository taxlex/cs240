#ifndef ANTHILL_H
#define ANTHILL_H
#include "Ant.h"
#include "LinkedList.h"

using namespace std;
class AntHill{
	public:
		AntHill();
		~AntHill();
		void addAnt();
		bool removeAnt(int);
		Ant * getAnt(int);
		void printHillInfo();
		int getCurrentNumAnts(){return currentAnts;}
		void move();
		void turn();
		void antHillAttacked();
	private:
		int currentAnts;
		LinkedList * ants;
		int antFood;
};

#endif
