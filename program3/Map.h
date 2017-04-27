#ifndef MAP_H
#define MAP_H
using namespace std;


class Map{
	public:
		Map(string filename);
		City* findByName(string cityName);
}


#endif
