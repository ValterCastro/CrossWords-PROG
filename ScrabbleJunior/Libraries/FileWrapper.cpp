#include "FileWrapper.h"

FileWrapper::FileWrapper() {}

bool FileWrapper::isValidBoardFilename(std::string filename) {
  bool validFilename;

  std::ifstream inFile;
  inFile.open(filename);

  if (inFile.is_open()) {
    validFilename = true;
    inFile.close();
  } else {
    validFilename = false;
  }

  return validFilename;
}

std::vector<unsigned short> FileWrapper::loadBoardSize(std::string filename) {
  std::ifstream boardFile;
  std::vector<unsigned short> sizes;
  std::string sizeString;
  unsigned short size;

  boardFile.open(filename);
  getline(boardFile, sizeString);
  boardFile.close();

  std::replace(sizeString.begin(), sizeString.end(), 'X', ' ');
  std::replace(sizeString.begin(), sizeString.end(), 'x', ' ');
  std::stringstream ss(sizeString);

  while (ss >> size) sizes.push_back(size);

  return sizes;
};

std::vector<std::string> FileWrapper::loadBoardWords(std::string filename) {
  std::ifstream boardFile;
  std::string ignoredLine;
  std::string word;
  std::vector<std::string> words;

  boardFile.open(filename);
  getline(boardFile, ignoredLine);

  while (!boardFile.eof()) {
    getline(boardFile, word);
    if (word.empty()) break;
    words.push_back(word);
  }

  boardFile.close();

  return words;
};