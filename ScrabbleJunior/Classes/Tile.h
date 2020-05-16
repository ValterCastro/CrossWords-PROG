#ifndef TILE_H
#define TILE_H

#include <vector>

class Tile {
 public:
  Tile(char letter, std::vector<unsigned short> wordIds);

  char getLetter();
  bool getPlayed();
  std::vector<unsigned short> getWordIds();

  void setPlayed(bool played);

 private:
  char letter;
  bool played;
  std::vector<unsigned short> wordIds;
};

#endif