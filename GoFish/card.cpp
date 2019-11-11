#include "card.h"
using namespace std;

Card::Card() {
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Card::Suit s) {
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    return rankString(myRank) + suitString(mySuit);
}

bool Card::sameSuitAs(const Card &c) const {
    return suitString(c.mySuit) == suitString(mySuit);
}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Card::Suit s) const {
    switch (s){
        case spades:
            return "s";
        case hearts:
            return "h";
        case diamonds:
            return "d";
        case clubs:
            return "c";
    }

}

string Card::rankString(int r) const {
    string rank[] = {"0","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    return rank[r];
}

bool Card::operator==(const Card &rhs) const {
    if(this->myRank == rhs.myRank)
    {
        if(this->mySuit == rhs.mySuit)
        {
            return true;
        }
    }
    return false;
}

bool Card::operator!=(const Card &rhs) const {
    if(this->myRank != rhs.myRank)
    {
        return true;
    }
    return this->mySuit != rhs.mySuit;
}
