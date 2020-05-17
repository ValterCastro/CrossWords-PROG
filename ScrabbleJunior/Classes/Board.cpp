#include "Board.h"

Board::Board(){};

const char Board::INITIAL_ROW_LETTER = 'A';
const char Board::INITIAL_COLLUMN_LETTER = 'a';

std::string Board::getFilename() const { return this->filename; };

std::vector<std::vector<Tile>> Board::getTiles() const { return this->tiles; };

unsigned short Board::getNrRows() const { return this->tiles.size(); }

unsigned short Board::getNrCollumns() const { return this->tiles[0].size(); }

std::vector<Word> Board::getWords() const { return this->words; };

Tile Board::getTile(unsigned short rowIndex,
                    unsigned short collumnIndex) const {
  return this->tiles.at(rowIndex).at(collumnIndex);
};

Word Board::getWord(unsigned short id) const { return this->words[id - 1]; };

bool Board::isMoveValid(std::string moveString, std::vector<char> playerHand,
                        unsigned short blockedWordId = 0) const {
  bool isValid = false;
  char letter = moveString[0];
  unsigned short rowIndex = (moveString[2] - Board::INITIAL_ROW_LETTER);
  unsigned short collumnIndex = (moveString[3] - Board::INITIAL_COLLUMN_LETTER);
  Tile tile = this->getTile(rowIndex, collumnIndex);

  // letter in hand?
  std::vector<char>::iterator it;
  it = std::find(playerHand.begin(), playerHand.end(), letter);
  if (it == playerHand.end()) return false;

  // letter in position tile and not played?
  if (tile.getLetter() != letter) return false;
  if (tile.getPlayed() == true) return false;

  // letter is first available letter?
  for (size_t i = 0; i < tile.getWordIds().size(); i++) {
    Word word = this->getWord(tile.getWordIds()[i]);
    if (word.getFirstAvailableLetter() == letter) break;
    if (i == tile.getWordIds().size() - 1) return false;
  }

  // letter is not of a blocked wordId?
  if (blockedWordId != 0 && tile.getWordIds().size() == 1 &&
      tile.getWordIds().front() == blockedWordId)
    return false;

  return true;
}

void Board::setFilename(std::string filename) { this->filename = filename; };

void Board::setTiles(std::vector<std::vector<Tile>> tiles) {
  this->tiles = tiles;
};

void Board::setTileAsPlayed(unsigned short rowIndex,
                            unsigned short collumnIndex) {
  this->tiles.at(rowIndex).at(collumnIndex).setPlayed(true);
};

void Board::setWords(std::vector<Word> words) { this->words = words; }