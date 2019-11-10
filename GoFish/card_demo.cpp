// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    int numCards = 5;

    /*Deck d1;
    cout << d1.dealCard().toString() << endl;
    cout << d1.size() << endl;
    cout << d1.dealCard().toString() << endl;
    cout << d1.size() << endl;*/

    /*Card c1;
    Card c2(2, Card::spades);
    Card c3(13, Card::hearts);

    cout << "Does heart == heart?" << c1.sameSuitAs(c2) << endl;
    cout << "Does heart == spades?" << c2.sameSuitAs(c3) << endl;
    cout << "The rank of ace" << c1.getRank() << endl;
    cout << "The rank of king" << c3.getRank() << endl;
    cout << "The string of c3" << c3.toString() << endl;

    return 0;*/

    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   



