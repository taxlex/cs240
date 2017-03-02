#include "Deck.h"

Deck::Deck(){
	stack = new Queue<Card>();
	for(int i = 2; i< 53; i++){
		for(int y = 1; y < 5; y++){
			Card * temp = new Card(y,i); 
			stack->enqueue(temp);
		}
	}
}
Card Deck::draw(){
	return stack->dequeue();
}	
bool Deck::empty(){
	return stack->empty();
}
