#ifndef MAP_H
#define MAP_H
#include "City.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


class Map{
	public:
		Map(string filename);
		~Map();
		City* findByName(string cityName);
		void setAdjacencies(City * currCity);
		vector<City *> shortestPath(City * start, City * dest);
		unsigned int pathDistance(City * start, City * dest);
		void addCity(City* cit){cities.push_back(cit);};
		list<City*> getCities(){return cities;};
		void nextShortest(City * start, City * dest);
		void getWay(City * dest);
	private:
		list<City*> cities;
		vector<City*> bestWay;
};


#endif
