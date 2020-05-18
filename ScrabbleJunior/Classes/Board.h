#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "Tile.h"
#include "Word.h"

class Board {
 public:
  Board();

  const char static INITIAL_ROW_LETTER;
  const char static INITIAL_COLLUMN_LETTER;

  std::string getFilename() const;
  std::vector<std::vector<Tile>> getTiles() const;
  unsigned short getNrRows() const;
  unsigned short getNrCollumns() const;
  std::vector<Word> getWords() const;

  Tile getTile(unsigned short rowIndex, unsigned short collumnIndex) const;
  Word getWord(unsigned short id) const;
  bool isMoveValid(std::string moveString, std::vector<char> playerHand,
                   unsigned short blockedWordId) const;

  void setFilename(std::string filename);
  void setTiles(std::vector<std::vector<Tile>> tiles);
  void setTileAsPlayed(unsigned short rowIndex, unsigned short collumnIndex);
  void setWords(std::vector<Word> words);

 private:
  std::string filename;
  std::vector<std::vector<Tile>> tiles;
  std::vector<Word> words;
};

#endif
