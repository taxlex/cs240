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
		int getCurrentNumAnts(){return currentAnts;}
		void turn();
	private:
		int currentAnts;
		LinkedList * ants;
		int antFood;
		int turnNum;
};

#endif
