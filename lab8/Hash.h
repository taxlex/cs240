#ifndef HASH_H
#define HASH_H
#include <string>

using namespace std;

class Hash{
	public:
		Hash(unsigned int size);
		bool insert(string key, string value);
		bool remove(string key);
		string find(string key);
		bool empty();
		bool size();
		void printHash();
		int hasher(string key);
	private:
		
}




#endif
