
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <string>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int main( )
{
    int numCards = 5;
    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    Card c1, c2;
    int books = 0;

    while(d.size() != 0)
    {
        if(p1.checkHandForBook(c1, c2))
        {
            cout << p1.getName() << "books the " << c1.getRank();
            books++;
        }
        if(p2.checkHandForBook(c1, c2))
        {
            cout << p2.getName() << "books the " << c1.getRank();
            books++;
        }

        c1 = p1.chooseCardFromHand();
        cout << p1.getName() << "asks - Do you have a " << c1.getRank();

        bool fish = false;
        if(p2.cardInHand(c1))
        {
            cout << p2.getName() << "says - Yes. I have a " << c1.rankString(c1.getRank());
            fish = false;
        }
        else
        {
            cout << p2.getName() << "says - Go Fish";
            fish = true;
        }

        if(fish)
        {
            dealHand(d, p1, 1);
        }
        if(!fish)
        {
            p2.removeCardFromHand(c1);
            p1.addCard(c1);
        }

        if(p1.checkHandForBook(c1, c2))
        {
            cout << p1.getName() << "books the " << c1.getRank();
            books++;
        }
        if(p2.checkHandForBook(c1, c2))
        {
            cout << p2.getName() << "books the " << c1.getRank();
            books++;
        }

        c1 = p2.chooseCardFromHand();
        cout << p2.getName() << "asks - Do you have a " << c1.getRank();

        fish = false;
        if(p2.cardInHand(c1))
        {
            cout << p1.getName() << "says - Yes. I have a " << c1.rankString(c1.getRank());
            fish = false;
        }
        else
        {
            cout << p1.getName() << "says - Go Fish";
            fish = true;
        }

        if(fish)
        {
            dealHand(d, p2, 1);
        }
        if(!fish)
        {
            p1.removeCardFromHand(c1);
            p2.addCard(c1);
        }
    }

}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}


