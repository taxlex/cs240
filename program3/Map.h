#ifndef MAP_H
#define MAP_H
#include "City.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;


class Map{
	public:
		Map(string filename);
		City* findByName(string cityName);
		void setAdjacencies(City * currCity);
		vector<City *> shortestPath(City * start, City * dest);
		unsigned int pathDistance(City * start, City * dest);
		void addCity(City* cit){cities.push_back(cit);};
		list<City*> getCities(){return cities;};
	private:
		list<City*> cities;
};


#endif
