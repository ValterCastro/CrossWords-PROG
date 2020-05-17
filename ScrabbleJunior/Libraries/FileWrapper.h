#ifndef FILE_WRAPPER_H
#define FILE_WRAPPER_H

#include <stdio.h>

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Classes/Board.h"

// Responsible for wrapping all file operations
class FileWrapper {
 public:
  FileWrapper();

  bool static isValidBoardFilename(std::string filename);
  std::vector<unsigned short> static loadBoardSize(std::string filename);
  std::vector<std::string> static loadBoardWords(std::string filename);
};

#endif
