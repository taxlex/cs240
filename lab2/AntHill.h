#ifndef ANTHILL_H
#define ANTHILL_H

using namespace std;
class Ant{
	public:
		Ant();
		Ant(int);
		void move();
		int getID();
		int getX();
		int getY();
	private:
		int id;
		int x;
		int y;
};
class AntHill{
	public:
		AntHill(int);
		bool addAnt();
		Ant getAnt(int);
		bool changeMax(int);
		void printHillInfo();
		int getCurrentNumAnts();
		int getMaxAnts();
		void move();
	private:
		int max_ants;
		int current_ants;
		Ant ants[100];
		int next_id;
};

#endif
