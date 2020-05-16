#include "Tile.h"

Tile::Tile(char letter, std::vector<unsigned short> wordIds) {
  this->letter = letter;
  this->played = false;
  this->wordIds = wordIds;
};

char Tile::getLetter() { return this->letter; };

bool Tile::getPlayed() { return this->played; };

std::vector<unsigned short> Tile::getWordIds() { return this->wordIds; }

void Tile::setPlayed(bool played) { this->played; };