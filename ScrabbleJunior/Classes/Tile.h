#ifndef TILE_H
#define TILE_H

#include <vector>

class Tile {
 public:
  Tile();

  char getLetter();
  bool getPlayed();
  std::vector<unsigned short> getWordIds();

  void setLetter(char letter);
  void setPlayed(bool played);
  void addWordId(unsigned short wordId);

 private:
  char letter;
  bool played;
  std::vector<unsigned short> wordIds;
};

#endif