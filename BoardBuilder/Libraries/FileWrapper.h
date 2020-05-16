#ifndef FILE_WRAPPER_H
#define FILE_WRAPPER_H

#include <stdio.h>

#include <fstream>
#include <set>
#include <string>

#include "Classes/Board.h"

// Responsible for wrapping all file operations
class FileWrapper {
 public:
  FileWrapper();

  std::set<std::string> static loadWordsFile();
  bool static isValidFilename(std::string filename);
  void static saveBoardToFile(Board board);
};

#endif
