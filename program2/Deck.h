#ifndef DECK_H
#define DECK_H
#include "Queue.h"
#include "Card.h"

using namespace std;
class Deck{
	public:
		Deck();
		~Deck();
		Card draw();
		bool empty();
		void shuffle();
	private:
		Queue<Card*> stack;
};

#endif
