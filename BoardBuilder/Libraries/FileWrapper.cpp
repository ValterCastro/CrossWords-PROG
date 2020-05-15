#include "FileWrapper.h"

#include <stdio.h>
#include <fstream>
#include <string>
#include <set>

FileWrapper::FileWrapper() {}

std::set<std::string> FileWrapper::loadWordsFile() {
    std::ifstream wordsFile;
    std::set<std::string> words;
    std::string word;

    wordsFile.open("WORDS.TXT");
    
    // Note: no need to handle empty file because we control this file
    while(!wordsFile.eof())
    {
        getline(wordsFile, word);
        words.insert(word);
    }
    
    wordsFile.close();

    return words;
}

bool FileWrapper::isValidFilename(std::string filename){
    bool validFilename;
    
    std::ofstream outFile;
	outFile.open(filename);
		
	if (outFile.is_open()) {
		validFilename = true;
		outFile.close();
		std::remove(filename.c_str());
	}
    else
    {
        validFilename = false;
    }

    return validFilename;
}

bool FileWrapper::saveBoardToFile(std::string boardName, std::string word){
    std::ofstream boardFile;
    
    boardFile.open(boardName + ".txt");
    boardFile << word << '\n';
    boardFile.close();

    return true;
}
