#include "City.h"
#include <string>
#include <list>
using namespace std;


City::City(string cityName, int xCoor, int yCoor){
	name = cityName;
	x = xCoor;
	y = yCoor;
	cities.push_back(this);
}
list<City*> getAdjacent();
bool operator<(City &c);
