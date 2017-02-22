#ifndef ANT_H
#define ANT_H

using namespace std;
class Ant{
	public:
		Ant(int);
		Ant(const Ant&);
		void move();
		int getID(){return id;}
		int getX(){return x;}
		int getY(){return y;}
		int getExp(){return exp;}
		Ant * fight(Ant *);
	private:
		int id;
		int x;
		int y;
		int exp;
};
#endif
