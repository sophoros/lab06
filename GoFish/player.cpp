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
    int hand = 0;
    for (auto i : myHand) {
        hand ++;
    }
    return hand;
}

int Player::getBookSize() const {
    return 0;
}
