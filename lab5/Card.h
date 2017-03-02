#ifndef CARD_H
#define CARD_H

using namespace std;
class Card{
	public:
		Card(int suit, int value);
		int getValue(){return value;};
		int getSuit(){return suit;};
		bool operator==(const Card &other);
	private:
		int value;
		int suit;
};

#endif
