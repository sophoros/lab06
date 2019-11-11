#include "deck.h"
using namespace std;

Deck::Deck() {
    for (int i = 1; i <= 13; ++i) {
        myCards[i - 1] = Card(i, Card::clubs);
    }
    for (int i = 1; i <= 13; ++i) {
        myCards[i + 12] = Card(i, Card::diamonds);
    }
    for (int i = 1; i <= 13; ++i) {
        myCards[i + 25] = Card(i, Card::hearts);
    }
    for (int i = 1; i <= 13; ++i) {
        myCards[i + 38] = Card(i, Card::spades);
    }
    myIndex = 0;
}

void Deck::shuffle() {
    for(int card = 0; card < (52 - myIndex); card++)
    {
        int random = rand() % (52 - myIndex);
        if(random != card)
        {
            Card temp = myCards[card];
            myCards[card] = myCards[random];
            myCards[random] = temp;
        }
    }
}

Card Deck::dealCard() {
    if (myIndex < 52) {
        return myCards[myIndex++];
    }
}

int Deck::size() const {
    return 52 - myIndex;
}
