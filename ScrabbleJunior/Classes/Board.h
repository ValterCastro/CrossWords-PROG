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

  std::string getFilename();
  std::vector<std::vector<Tile>> getTiles();
  std::vector<Word> getWords();

  Tile getTile(unsigned short rowIndex, unsigned short collumnIndex);
  Word getWord(unsigned short id);

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
