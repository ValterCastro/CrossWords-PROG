#include "Board.h"

Board::Board() {}
const char Board::INITIAL_ROW_LETTER = 'A';
const char Board::INITIAL_COLLUMN_LETTER = 'a';

// getters

std::string Board::getName() const { return this->name; }

unsigned short Board::getNrRows() const { return this->tiles.size(); }

unsigned short Board::getNrCollumns() const { return this->tiles[0].size(); }

std::vector<std::vector<char>> Board::getTiles() const { return this->tiles; }

std::vector<Word> Board::getWords() const { return this->words; }

// setters

void Board::setNrRows(unsigned short nrRows) { this->tiles.resize(nrRows); }

void Board::setNrCollumns(unsigned short nrCollumns) {
  unsigned short nrRows;

  nrRows = this->getNrRows();
  for (size_t i = 0; i < nrRows; i++) {
    this->tiles[i].resize(nrCollumns);
  }
}

void Board::setName(std::string name) { this->name = name; }

void Board::setTile(unsigned short row, unsigned short collumn, char letter) {
  this->tiles.at(row).at(collumn) = letter;
}

bool Board::addWord(Word word) {
  if (!this->wordCanBeAdded(word)) {
    return false;
  }

  this->addWordToTiles(word);
  this->words.push_back(word);

  return true;
}

// private

bool Board::wordCanBeAdded(Word word) const {
  std::vector<char> position;
  WordOrientation orientation;
  unsigned short rowIndex;
  unsigned short collumnIndex;

  position = word.getPosition();
  orientation = word.getOrientation();
  rowIndex = (position[0] - Board::INITIAL_ROW_LETTER);
  collumnIndex = (position[1] - Board::INITIAL_COLLUMN_LETTER);

  bool valid = (orientation == WordOrientation::Horizontal)
                   ? this->checkHorizontal(word, rowIndex, collumnIndex)
                   : this->checkVertical(word, rowIndex, collumnIndex);

  return valid;
}

bool Board::checkHorizontal(Word word, unsigned short rowIndex,
                            unsigned short collumnIndex) const {
  char tile;

  for (size_t i = 0; i < word.getWord().size(); i++) {
    if (this->getNrCollumns() <= (collumnIndex + i)) return false;

    tile = this->tiles[rowIndex][collumnIndex + i];

    if (tile != '\0' && tile != word.getWord()[i]) return false;
  }

  return true;
}

bool Board::checkVertical(Word word, unsigned short rowIndex,
                          unsigned short collumnIndex) const {
  char tile;

  for (size_t i = 0; i < word.getWord().size(); i++) {
    if (this->getNrRows() <= (rowIndex + i)) return false;

    tile = this->tiles[rowIndex + i][collumnIndex];

    if (tile != '\0' && tile != word.getWord()[i]) return false;
  }

  return true;
}

void Board::addWordToTiles(Word word) {
  std::vector<char> position;
  WordOrientation orientation;
  unsigned short rowIndex;
  unsigned short collumnIndex;

  position = word.getPosition();
  orientation = word.getOrientation();
  rowIndex = (position[0] - Board::INITIAL_ROW_LETTER);
  collumnIndex = (position[1] - Board::INITIAL_COLLUMN_LETTER);

  if (orientation == WordOrientation::Horizontal) {
    for (size_t i = 0; i < word.getWord().size(); i++) {
      this->setTile(rowIndex, collumnIndex + i, word.getWord()[i]);
    }
  } else {
    for (size_t i = 0; i < word.getWord().size(); i++) {
      this->setTile(rowIndex + i, collumnIndex, word.getWord()[i]);
    }
  }
}