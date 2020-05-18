#include "BoardLoadService.h"

BoardLoadService::BoardLoadService() {}

void BoardLoadService::call(Board &board) {
  std::vector<std::vector<Tile>> tiles;
  std::vector<Word> words;
  std::vector<unsigned short> sizes;
  std::vector<std::string> wordStrings;
  std::vector<std::vector<std::string>> parsedWords;

  sizes = FileWrapper::loadBoardSize(board.getFilename());
  BoardLoadService::resizeTiles(tiles, sizes);

  wordStrings = FileWrapper::loadBoardWords(board.getFilename());
  parsedWords = BoardLoadService::parseWords(wordStrings);

  std::vector<std::string> parsedWord;
  for (size_t i = 0; i < parsedWords.size(); i++) {
    parsedWord = parsedWords[i];
    // add each parsed word to tiles and words
    BoardLoadService::addParsedWord(parsedWord, i + 1, tiles, words);
  }

  board.setTiles(tiles);
  board.setWords(words);
}

// private

void BoardLoadService::resizeTiles(std::vector<std::vector<Tile>> &tiles,
                                   std::vector<unsigned short> sizes) {
  unsigned short nrRows;
  unsigned short nrCollumns;

  nrRows = sizes[0];
  nrCollumns = sizes[1];

  tiles.resize(nrRows);
  for (size_t i = 0; i < nrRows; i++) {
    for (size_t n = 0; n < nrCollumns; n++) {
      tiles[i].resize(nrCollumns);
    }
  }
}

std::vector<std::vector<std::string>> BoardLoadService::parseWords(
    std::vector<std::string> words) {
  std::vector<std::vector<std::string>> parsedWords;
  std::string wordPart;

  for (size_t i = 0; i < words.size(); i++) {
    std::stringstream ss(words[i]);
    std::vector<std::string> parsedWord;  // position, orientation, word

    while (ss >> wordPart) parsedWord.push_back(wordPart);

    parsedWords.push_back(parsedWord);
  }

  return parsedWords;
}

void BoardLoadService::addParsedWord(std::vector<std::string> parsedWord,
                                     unsigned short wordId,
                                     std::vector<std::vector<Tile>> &tiles,
                                     std::vector<Word> &words) {
  unsigned short rowIndex;
  unsigned short collumnIndex;

  rowIndex = (parsedWord[0][0] - Board::INITIAL_ROW_LETTER);
  collumnIndex = (parsedWord[0][1] - Board::INITIAL_COLLUMN_LETTER);

  for (size_t n = 0; n < parsedWord[2].size(); n++) {
    if (parsedWord[1] == "H") {
      tiles[rowIndex][collumnIndex + n].setLetter(parsedWord[2][n]);
      tiles[rowIndex][collumnIndex + n].addWordId(wordId);
    } else {
      tiles[rowIndex + n][collumnIndex].setLetter(parsedWord[2][n]);
      tiles[rowIndex + n][collumnIndex].addWordId(wordId);
    }
  }

  words.push_back(Word::Word(wordId, parsedWord[2]));
}