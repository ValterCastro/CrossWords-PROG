#include "Board.h"

Board::Board(){};

std::vector<std::vector<Tile>> Board::getTiles() { return this->tiles; };
std::map<unsigned short, Word> Board::getWords() { return this->words; };

Tile Board::getTile(unsigned short rowIndex, unsigned short collumnIndex) {
  return this->tiles.at(rowIndex).at(collumnIndex);
};

Word Board::getWord(unsigned short id) { return this->words.at(id); };

void Board::setTiles(std::vector<std::vector<Tile>> tiles) {
  this->tiles = tiles;
};

void Board::setTileAsPlayed(unsigned short rowIndex,
                            unsigned short collumnIndex) {
  this->tiles.at(rowIndex).at(collumnIndex).setPlayed(true);
};

void Board::addWord(Word word) { this->words.at(word.getId()) = word; };
