#include "City.h"
#include <cmath>
#include <string>
#include <list>
using namespace std;


City::City(string cityName, int xCoor, int yCoor){
	name = cityName;
	x = xCoor;
	y = yCoor;
}
list<City*> City::getAdjacent(){
	return this->adjacencies;
}
void City::setAdjacent(list<City*> anAdjacent){
	adjacencies = anAdjacent;
}
bool City::operator<(City &c){
	if(this->getName().length() < c.getName().length()) return true;
	return false;
}
