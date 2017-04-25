#ifndef HASH_H
#define HASH_H
#include <string>

using namespace std;
class KeyVal{
	public:
		KeyVal();
		KeyVal(string aKey, string aValue);
		string getKey(){return key;};
		string getValue(){return value;};
		string key;
		string value;

};
class Hash{
	public:
		Hash(unsigned int size);
		bool insert(string key, string value);
		bool remove(string key);
		string find(string key);
		bool empty();
		int size();
		void printHash();
		int Hasher(string key);
	private:
		KeyVal ** arr;
		int arrSize;
};



#endif
