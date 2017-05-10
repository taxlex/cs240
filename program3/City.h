#ifndef CITY_H
#define CITY_H
#include <string>
#include <list>
using namespace std;

class City{
	public:
		City(string cityName, int xCoor, int yCoor);
		string getName(){return name;};
		int getXCoor(){return x;};
		int getYCoor(){return y;};
		list<City*> getAdjacent();
		void setAdjacent(list<City*> anAdjacent);
		bool operator<(City &c);



		int distance;
		City* optimalPrevious;
		bool explored;
	private:
		string name;
		int x;
		int y;
		list<City*> adjacencies;
};


#endif
