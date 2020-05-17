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
  std::string getName() const;
  unsigned short getNrRows() const;
  unsigned short getNrCollumns() const;
  std::vector<std::vector<char>> getTiles() const;
  std::vector<Word> getWords() const;

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

  bool wordCanBeAdded(Word word) const;
  bool checkHorizontal(Word word, unsigned short rowIndex,
                       unsigned short collumnIndex) const;
  bool checkVertical(Word word, unsigned short rowIndex,
                     unsigned short collumnIndex) const;

  void addWordToTiles(Word word);
};

#endif