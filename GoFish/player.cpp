#include "player.h"
using namespace std;

Player::Player() {

}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
    removeCardFromHand(c1);
    removeCardFromHand(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2) {
    for (int i = 0; i < myHand.size() - 1; ++i) {
        for (int j = i + 1; j < myHand.size(); ++j) {
            if (myHand[i].getRank() == myHand[j].getRank()){
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;
}

bool Player::rankInHand(Card c) const {
    for (auto i : myHand){
        if (i.getRank() == c.getRank()) {
            return true;
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const {
    int random = rand() % myHand.size();
    return myHand[random];
}

bool Player::cardInHand(Card c) const {
    for (auto i : myHand) {
        if (i == c){
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {
    for (int i = 0; i < myHand.size(); ++i) {
        if (myHand.at(i) == c){
            myHand.erase(myHand.begin() + i);
            return c;
        }
    }
    return {0,Card::spades};    //error card
}

string Player::showHand() const {
    string hand;
    for (auto i : myHand) {
        hand += i.toString();
    }
    return hand;
}

string Player::showBooks() const {
    string books;
    for (auto i : myBook) {
        books += i.toString();
    }
    return books;
}

int Player::getHandSize() const {
    return myHand.size();
}

int Player::getBookSize() const {
    return myBook.size();
}
