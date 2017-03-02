#ifndef DECK_H
#define DECK_H
#include "Queue.h"
#include "Card.h"

using namespace std;
class Deck{
	public:
		Deck();
		Card draw();
		bool empty();
	private:
		Queue<Card> * stack;
};

#endif
