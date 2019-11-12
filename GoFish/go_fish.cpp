
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
    cout << endl;

    Card c1, c2;
    int books = 0;

    while(d.size() != 0 || books < 26)
    {
        if(p1.getHandSize() != 0) {
            c1 = p1.chooseCardFromHand();

            cout << p1.getName() << " asks - Do you have a " << c1.rankString(c1.getRank()) << endl;

            bool fish = false;
            if (p2.cardInHand(c1)) {
                cout << p2.getName() << " says - Yes. I have a " << c1.rankString(c1.getRank()) << endl;
                fish = false;
            } else {
                cout << p2.getName() << " says - Go Fish" << endl;
                fish = true;
            }

            if (fish) {
                dealHand(d, p1, 1);
            }
            if (!fish) {
                c2 = p2.removeCardFromHand(c1);
                p1.addCard(c2);
            }

            if (p1.checkHandForBook(c1, c2)) {
                cout << p1.getName() << " books the " << c1.getRank() << endl;
                p1.bookCards(c1, c2);
                books++;
            }
            /*if(p2.checkHandForBook(c1, c2))
            {
                cout << p2.getName() << " books the " << c1.getRank() << endl;
                p2.bookCards(c1, c2);
                books++;
            }*/

            cout << endl;
        }
        else
        {
            cout << endl;
            dealHand(d, p1, 1);
        }

        if(p2.getHandSize() != 0) {
            c1 = p2.chooseCardFromHand();
            cout << p2.getName() << " asks - Do you have a " << c1.rankString(c1.getRank()) << endl;

            bool fish = false;
            if (p1.cardInHand(c1)) {
                cout << p1.getName() << " says - Yes. I have a " << c1.rankString(c1.getRank()) << endl;
                fish = false;
            } else {
                cout << p1.getName() << " says - Go Fish" << endl;
                fish = true;
            }

            if (fish) {
                dealHand(d, p2, 1);
            }
            if (!fish) {
                c2 = p1.removeCardFromHand(c1);
                p2.addCard(c2);
            }

            /*if(p1.checkHandForBook(c1, c2))
            {
                cout << p1.getName() << " books the " << c1.getRank() << endl;
                p1.bookCards(c1, c2);
                books++;
            }*/
            if (p2.checkHandForBook(c1, c2)) {
                cout << p2.getName() << " books the " << c1.getRank() << endl;
                p2.bookCards(c1, c2);
                books++;
            }

            cout << endl;
        }
        else
        {
            cout << endl;
            dealHand(d, p2, 1);
        }
    }

    if(p1.getBookSize() > p2.getBookSize())
    {
        cout << p1.getName() << " Wins!" << endl;
    }
    if(p2.getBookSize() > p1.getBookSize())
    {
        cout << p2.getName() << " Wins!" << endl;
    }
    if(p1.getBookSize() == p2.getBookSize())
    {
        cout << "It's a Tie!" << endl;
    }

    cout << books;
    return EXIT_SUCCESS;
}

void dealHand(Deck &d, Player &p, int numCards)
{
    Card temp;
    if(d.size() > 0)
    {
        for (int i=0; i < numCards; i++)
        {
            temp = d.dealCard();
            p.addCard(temp);
        }
        cout << p.getName() << " draws " << temp.toString() << endl;
    }
}


