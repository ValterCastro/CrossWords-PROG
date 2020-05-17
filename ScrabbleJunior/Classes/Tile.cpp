#include "Tile.h"

Tile::Tile() {
  this->letter = '\0';
  this->played = false;
}

char Tile::getLetter() { return this->letter; };

bool Tile::getPlayed() { return this->played; };

std::vector<unsigned short> Tile::getWordIds() { return this->wordIds; }

void Tile::setLetter(char letter) { this->letter = letter; };

void Tile::setPlayed(bool played) { this->played; };

void Tile::addWordId(unsigned short wordId) {
  this->wordIds.push_back(wordId);
};