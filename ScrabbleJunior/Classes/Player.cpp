#include "Player.h"

Player::Player(unsigned int id, std::vector<char> hand,  unsigned int score = 0) {
    this->id = id;
    this->score = score;
    this->hand = hand;
}

unsigned int Player::getID() const {
    return id;
}

std::vector<char> Player::getHand() const {
    return hand;
}

unsigned int Player::getScore() const {
    return score;
}

void Player::setHand(std::vector<char> hand) {
    //to be filled
}

void Player::setID(unsigned int id) {
    this->id = id;
}

void Player::setScore(unsigned int score) {
    this->score = score;
}