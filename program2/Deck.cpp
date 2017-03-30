#include <stdio.h>
#include <stdlib.h>

#include "Deck.h"

Deck::Deck(){
	for(int i = 2; i< 15; i++){
		for(int y = 1; y < 5; y++){
			Card * temp = new Card(y,i); 
			stack.enqueue(temp);
		}
	}
}
Card Deck::draw(){
	Card * copy = stack.dequeue();
	Card ret = *copy;
	delete copy;
	return ret;
}	
bool Deck::empty(){
	return stack.empty();
}
void Deck::shuffle(){
	int runs = rand()%25;
	runs += 27;
	for(int i = 0; i < runs; i++){
		int subRuns = rand()%25;
		Queue<Card*> temp;
		for(int y = 0; y < subRuns; y++){
			Card * copy = stack.dequeue();
			temp.enqueue(copy);
		}
		for(int y = 0; y < subRuns; y++){
			Card * copy = temp.dequeue();
			stack.enqueue(copy);
		}
	}
}
