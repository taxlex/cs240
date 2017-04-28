#include "City.h"
#include <cmath>
#include <string>
#include <list>
using namespace std;


City::City(string cityName, int xCoor, int yCoor){
	name = cityName;
	x = xCoor;
	y = yCoor;
	cities.push_back(this);
}
list<City*> getAdjacent(){
	City * closestLeft;
	City * closestRight;
	City * closestAbove;
	City * closestBelow;

	list<City*> ret;
	list<City*> iterator it;
	for (it = cities.begin(); it != cities.end(); ++it){
		if(it->getx() == x && it->getY() == y);
		else if(it->getx() == x){
			if(it->getY() > y){
				if(closestAbove == NULL){
					closestAbove = it;
				}
				else if(abs(closestAbove->getY()-y) > abs(it->getY() - y)){
					closestAbove = it;
				}
			}
			else{
				if(it->getY() > y){
					if(closestBelow == NULL){
						closestBelow = it;
					}
					else if(abs(closestBelow->getY()-y) > abs(it->getY() - y)){
						closestBelow = it;
					}
				}
			}
		}
		else if(it->getY() == y){
			if(it->getX() > x){
				if(closestRight == NULL){
					closestRight = it;
				}
				else if(abs(closestRight->getX()-x) > abs(it->getX() - x)){
					closestRight it;
				}
			}
			else{
				if(it->getX() > x){
					if(closestLeft == NULL){
						closestLeft = it;
					}
					else if(abs(closestLeft->getX()-x) > abs(it->getX() - x)){
						closestLeft = it;
					}
				}
			}
		}
	}
	if(closestLeft != NULL) ret.push_back(closestLeft);
	if(closestRight != NULL) ret.push_back(closestRight);
	if(closestBelow != NULL) ret.push_back(closestBelow);
	if(closestAbove != NULL) ret.push_back(closestAbove);
	return ret;
}
bool operator<(City &c);
