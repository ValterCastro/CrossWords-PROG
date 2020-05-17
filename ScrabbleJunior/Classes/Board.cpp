#include "Board.h"

Board::Board(){};

const char Board::INITIAL_ROW_LETTER = 'A';
const char Board::INITIAL_COLLUMN_LETTER = 'a';

std::string Board::getFilename() { return this->filename; };

std::vector<std::vector<Tile>> Board::getTiles() { return this->tiles; };

std::vector<Word> Board::getWords() { return this->words; };

Tile Board::getTile(unsigned short rowIndex, unsigned short collumnIndex) {
  return this->tiles.at(rowIndex).at(collumnIndex);
};

Word Board::getWord(unsigned short id) { return this->words[id - 1]; };

void Board::setFilename(std::string filename) { this->filename = filename; };

void Board::setTiles(std::vector<std::vector<Tile>> tiles) {
  this->tiles = tiles;
};

void Board::setTileAsPlayed(unsigned short rowIndex,
                            unsigned short collumnIndex) {
  this->tiles.at(rowIndex).at(collumnIndex).setPlayed(true);
};

void Board::setWords(std::vector<Word> words) { this->words = words; }