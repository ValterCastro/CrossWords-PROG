#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include "Word.h"

class Board {
public:
	Board();

	// getters
	std::string getName();
	unsigned short getNrRows();
	unsigned short getNrCollumns();
	std::vector<std::vector<char>> getTiles();
	std::vector<Word> getWords();

	// setters
	void setName(std::string name);
	void setNrRows(unsigned short nrRows);
	void setNrCollumns(unsigned short nrCollumns);
	void setTile(unsigned short row, unsigned short collumn, char letter);
	void addWord(Word word);

private:
	std::string name;
	std::vector<std::vector<char>> tiles;
	std::vector <Word> words;
};

#endif