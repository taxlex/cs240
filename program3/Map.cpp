#include "Map.h"
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

Map::Map(string filename){
	string name;
	string aX;
	string aY;
	int x;
	int y;
	ifstream input(filename.c_str());
	if(input){
		while(input >> name >> x >> y){

			City * temp = new City(name,x,y);
			addCity(temp);
			setAdjacencies(temp);
		}
	}
}
City* Map::findByName(string cityName){
	list<City*>::iterator it;
	for (it = cities.begin(); it != cities.end(); ++it){
		if(!(*it)->getName().compare(cityName)){
			return (*it);
		}
	}
	return NULL;
}
void Map::setAdjacencies(City * currCity){
	City * closestLeft;
	City * closestRight;
	City * closestAbove;
	City * closestBelow;
	int x = currCity->getXCoor();
	int y = currCity->getYCoor();

	list<City*> ret;
	list<City*>::iterator it;
	for (it = cities.begin(); it != cities.end(); ++it){
		if((*it)->getXCoor() == x && (*it)->getYCoor() == y);
		else if((*it)->getXCoor() == x){
			if((*it)->getYCoor() > y){
				if(closestAbove == NULL){
					closestAbove = (*it);
				}
				else if(abs(closestAbove->getYCoor()-y) > abs((*it)->getYCoor() - y)){
					closestAbove = (*it);
				}
			}
			else{
				if((*it)->getYCoor() > y){
					if(closestBelow == NULL){
						closestBelow = (*it);
					}
					else if(abs(closestBelow->getYCoor()-y) > abs((*it)->getYCoor() - y)){
						closestBelow = (*it);
					}
				}
			}
		}
		else if((*it)->getYCoor() == y){
			if((*it)->getXCoor() > x){
				if(closestRight == NULL){
					closestRight = (*it);
				}
				else if(abs(closestRight->getXCoor()-x) > abs((*it)->getXCoor() - x)){
					closestRight = (*it);
				}
			}
			else{
				if((*it)->getXCoor() > x){
					if(closestLeft == NULL){
						closestLeft = (*it);
					}
					else if(abs(closestLeft->getXCoor()-x) > abs((*it)->getXCoor() - x)){
						closestLeft = (*it);
					}
				}
			}
		}
	}
	if(closestLeft != NULL) ret.push_back(closestLeft);
	if(closestRight != NULL) ret.push_back(closestRight);
	if(closestBelow != NULL) ret.push_back(closestBelow);
	if(closestAbove != NULL) ret.push_back(closestAbove);
	currCity->setAdjacent(ret);
}
vector<City *> Map::shortestPath(City * start, City * dest){
	vector<City *> ret;
	return ret;
}
unsigned int Map::pathDistance(City * start, City * dest){
	return 1;
}