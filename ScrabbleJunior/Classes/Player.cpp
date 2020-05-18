#include "Player.h"

Player::Player(unsigned short id, std::string name) {
  this->id = id;
  this->name = name;
  this->score = 0;
}

unsigned short Player::getId() const { return this->id; }

std::string Player::getName() const { return this->name; }

std::vector<char> Player::getHand() const { return this->hand; }

unsigned short Player::getScore() const { return this->score; }

void Player::addLetter(char letter) { this->hand.push_back(letter); }

void Player::removeLetter(char letter) {
  std::vector<char>::iterator it;

  it = std::find(this->hand.begin(), this->hand.end(), letter);
  if (it != this->hand.end()) this->hand.erase(it);
}

void Player::setScore(unsigned short score) { this->score = score; }