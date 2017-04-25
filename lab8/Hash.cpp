#include "Hash.h"
#include <string>
#include <iostream>

KeyVal::KeyVal(){
	key = "";
	value = "";
}
KeyVal::KeyVal(string aKey, string aValue){
	key = aKey;
	value = aValue;
}
Hash::Hash(unsigned int size){
	arr = new KeyVal*[size];
	arrSize = size;
	for(int i = 0; i < size; i++){
		arr[i] = new KeyVal("","");
	}
}
Hash::~Hash(){
	for(int i = 0; i < size(); i++){
		delete arr[i];
	}
	delete[] arr;
}
bool Hash::insert(string key, string value){
	int index = Hasher(key);
	bool ins = false;
	for(int i = index; i < size(); i++){
		if(arr[i]->getKey().empty()){
			arr[i]->key = key;
			arr[i]->value = value;
			ins = true;
			break;
		}
	}
	if(!ins){
		for(int i = 0; i < index; i++){
			if(arr[i]->getKey().empty()){
				arr[i]->key = key;
				arr[i]->value = value;
				ins = true;
				break;
			}
		}
	}
	return ins;

}
bool Hash::remove(string key){
	bool ins = false;
	int index = Hasher(key);
	for(int i = index; i < size(); i++){
		if(arr[i]->key == key){
			arr[i]->key = "";
			arr[i]->value = "";
			ins = true;
			break;
		}
	}
	if(!ins){
		for(int i = 0; i < index; i++){
			if(arr[i]->key == key){
				arr[i]->key = "";
				arr[i]->value = "";
				ins = true;
				break;
			}
		}
	}
	return ins;
}
string Hash::find(string key){
	bool ins = false;
	int index = Hasher(key);
	for(int i = index; i < size(); i++){
		if(arr[i]->key == key){
			return arr[i]->value;
		}
	}
	if(!ins){
		for(int i = 0; i < index; i++){
			if(arr[i]->key == key){
				return arr[i]->value;
			}
		}
	}
	return "";
}
bool Hash::empty(){
	bool ret = true;
	for(int i = 0; i < size(); i++){
		if(arr[i]->getKey() != "") ret = false;
	}
	return ret;
}
int Hash::size(){
	return arrSize;
}
void Hash::printHash(){
	for(int i = 0; i < size(); i++){
		cout<< "index:" << i <<"     " << "key:" << arr[i]->getKey() <<"     " << "value:" << arr[i]->getValue()<<endl;
	}
}
int Hash::Hasher(string key){
	char firstLetter = key.at(0);
	return firstLetter%size();
}



