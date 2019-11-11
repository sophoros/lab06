#include "player.h"
using namespace std;

Player::Player() {

}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {

}

bool Player::checkHandForBook(Card &c1, Card &c2) {
    return false;
}

bool Player::rankInHand(Card c) const {
    return false;
}

Card Player::chooseCardFromHand() const {

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
        }
    }
    return c;
}

string Player::showHand() const {
    string hand;
    for (auto i : myHand) {
        hand += i.toString();
    }
    return hand;
}

string Player::showBooks() const {
    return std::__cxx11::string();
}

int Player::getHandSize() const {
    return myHand.size();
}

int Player::getBookSize() const {
    return 0;
}
