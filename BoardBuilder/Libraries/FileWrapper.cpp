#include "FileWrapper.h"

#include <stdio.h>
#include <fstream>
#include <string>
#include <set>

#include "Classes/Board.h"

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

void FileWrapper::saveBoardToFile(Board board){
    std::ofstream boardFile;
    std::vector<Word> words;
    char orientationChar;

    boardFile.open(board.getName() + ".txt");
    
    boardFile << board.getNrRows() << " x " << board.getNrCollumns() << '\n';

    words = board.getWords();
    for(size_t i = 0; i < words.size(); i++){
        Word word = words[i];
        orientationChar = word.getOrientation() == WordOrientation::Horizontal ? 'H' : 'V';

        boardFile << word.getPosition()[0] << word.getPosition()[1];
        boardFile << ' ' << orientationChar;
        boardFile << ' ' << word.getWord() << '\n';
    }
    
    boardFile << '\n';

    boardFile.close();
}
