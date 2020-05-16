#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>

#include "Word.h"

class Board {
 public:
  Board();
  const char static INITIAL_ROW_LETTER;
  const char static INITIAL_COLLUMN_LETTER;

  // getters
  std::string getName();
  unsigned short getNrRows();
  unsigned short getNrCollumns();
  std::vector<std::vector<char>> getTiles();
  std::vector<Word> getWords();

  // setters
  void setName(std::string name);
  void setNrRows(unsigned short nrRows);
  void setNrCollumns(unsigned short nrCollumns);
  void setTile(unsigned short row, unsigned short collumn, char letter);
  bool addWord(Word word);

 private:
  std::string name;
  std::vector<std::vector<char>> tiles;
  std::vector<Word> words;

  bool wordCanBeAdded(Word word);
  bool checkHorizontal(Word word, unsigned short rowIndex,
                       unsigned short collumnIndex);
  bool checkVertical(Word word, unsigned short rowIndex,
                     unsigned short collumnIndex);
  void addWordToTiles(Word word);
};

#endif