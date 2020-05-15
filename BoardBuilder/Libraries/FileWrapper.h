#ifndef FILE_WRAPPER_H
#define FILE_WRAPPER_H

#include <string>
#include <set>

// Responsible for wrapping all file operations
class FileWrapper {
public:
    FileWrapper();

    std::set<std::string> static loadWordsFile();
    bool static isValidFilename(std::string filename);
    bool static saveBoardToFile(std::string filename,  std::string word);
};

#endif
