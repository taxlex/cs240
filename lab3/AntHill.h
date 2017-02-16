#ifndef ANTHILL_H
#define ANTHILL_H
#include "Ant.h"

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
	private:
		int current_ants;
		Ant ** ants;
		int next_id;
};

#endif
