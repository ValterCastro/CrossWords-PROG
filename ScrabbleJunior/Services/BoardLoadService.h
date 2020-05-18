#ifndef BOARD_LOAD_SERVICE_H
#define BOARD_LOAD_SERVICE_H

#include <sstream>
#include <string>
#include <vector>

#include "../Classes/Board.h"
#include "../Classes/Tile.h"
#include "../Classes/Word.h"
#include "../Libraries/FileWrapper.h"

// Responsible for loading a file and setting board's tiles and words
class BoardLoadService {
 public:
  BoardLoadService();

  void static call(Board &board);

 private:
  void static resizeTiles(std::vector<std::vector<Tile>> &tiles,
                          std::vector<unsigned short> sizes);

  std::vector<std::vector<std::string>> static parseWords(
      std::vector<std::string> words);

  void static addParsedWord(std::vector<std::string> parsedWord,
                            unsigned short wordId,
                            std::vector<std::vector<Tile>> &tiles,
                            std::vector<Word> &words);
};

#endif