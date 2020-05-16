#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <vector>

#include "Tile.h"
#include "Word.h"

class Board {
 public:
  Board();

  std::vector<std::vector<Tile>> getTiles();
  std::map<unsigned short, Word> getWords();

  Tile getTile(unsigned short rowIndex, unsigned short collumnIndex);
  Word getWord(unsigned short id);

  void setTiles(std::vector<std::vector<Tile>> tiles);
  void setTileAsPlayed(unsigned short rowIndex, unsigned short collumnIndex);
  void addWord(Word word);

 private:
  std::vector<std::vector<Tile>> tiles;
  std::map<unsigned short, Word> words;
};

#endif
