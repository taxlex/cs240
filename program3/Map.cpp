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
Map::~Map(){
	list<City*>::iterator it;
	for (it = cities.begin(); it != cities.end(); ++it){
		delete (*it);
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
	City * closestLeft = NULL;
	City * closestRight = NULL;
	City * closestAbove = NULL;
	City * closestBelow = NULL;
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
				if(closestBelow == NULL){
					closestBelow = (*it);
				}
				else if(abs(closestBelow->getYCoor()-y) > abs((*it)->getYCoor() - y)){
					closestBelow = (*it);
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
				if(closestLeft == NULL){
					closestLeft = (*it);
				}
				else if(abs(closestLeft->getXCoor()-x) > abs((*it)->getXCoor() - x)){
					closestLeft = (*it);
				}
			}
		}
	}
	if(closestLeft != NULL) ret.push_back(closestLeft);
	if(closestRight != NULL) ret.push_back(closestRight);
	if(closestBelow != NULL) ret.push_back(closestBelow);
	if(closestAbove != NULL) ret.push_back(closestAbove);
	currCity->setAdjacent(ret);
	//Sets the adjacencies of adjacencies
	for(it = ret.begin(); it != ret.end(); it++){
		list<City*>::iterator its;
		list<City*> adj = (*it)->getAdjacent();
		bool inAdj = false;
		for(its = adj.begin(); its != adj.end(); its++){
			if(!(*its)->getName().compare(currCity->getName())) inAdj = true;
		}
		if(!inAdj) setAdjacencies((*it));
	}
}
vector<City *> Map::shortestPath(City * start, City * dest){
	list<City*>::iterator it;
	for (it = cities.begin(); it != cities.end(); ++it){
		(*it)->distance = INT_MAX;
		(*it)->optimalPrevious = NULL;
		(*it)->explored = false;
	}
	start->distance = 0;
	nextShortest(start, dest);
	bestWay.clear();
	getWay(dest);
	reverse(bestWay.begin(),bestWay.end());
	return bestWay;
}
void Map::nextShortest(City * start, City * dest){
	list<City*>::iterator it;
	list<City*> adj = start->getAdjacent();
	for(it = adj.begin(); it != adj.end(); ++it){
		if(start->getYCoor() == (*it)->getYCoor()){
			if((abs(start->getXCoor() - (*it)->getXCoor())+ start->distance) < (*it)->distance){
				(*it)->distance = abs(start->getXCoor() - (*it)->getXCoor()) + start->distance;
				(*it)->optimalPrevious = start;
			}
		}
		else{
			if((abs(start->getYCoor() - (*it)->getYCoor())+ start->distance) < (*it)->distance){
				(*it)->distance = abs(start->getYCoor() - (*it)->getYCoor()) + start->distance;
				(*it)->optimalPrevious = start;
			}
		}
	}
	start->explored = true;
	City * shortest = dest;
	bool more = false;
	for (it = cities.begin(); it != cities.end(); ++it){
		if(!(*it)->explored && (*it)->distance < shortest->distance){
			shortest = (*it);
			more = true;
		}
	}
	if(more){
		nextShortest(shortest, dest);
	}

}
void Map::getWay(City * dest){
	if(dest->distance != INT_MAX) bestWay.push_back(dest);
	if(dest->distance < INT_MAX && dest->distance > 0){
		getWay(dest->optimalPrevious);
	}
}
unsigned int Map::pathDistance(City * start, City * dest){
	vector<City *> path = shortestPath(start,dest);
	if(dest->distance == INT_MAX) return -1;
	return dest->distance;
}