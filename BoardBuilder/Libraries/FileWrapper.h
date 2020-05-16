#ifndef FILE_WRAPPER_H
#define FILE_WRAPPER_H

#include <string>
#include <set>

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
