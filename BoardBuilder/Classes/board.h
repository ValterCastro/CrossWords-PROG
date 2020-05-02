#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include "Word.h"

class Board {
public:
	Board();

	// getters
	std::vector<unsigned short> getSize();
	std::string getName();
	std::vector<std::vector<char>> getTiles();
	std::vector<Word> getWords();

	// setters
	void setSize(unsigned short nr_rows, unsigned short nr_collumns);
	void setName(std::string name);
	void setTile(unsigned short row, unsigned short collumn, char letter);
	void addWord(Word word);

private:
	std::vector<unsigned short> size;
	std::string name;
	std::vector<std::vector<char>> tiles;
	std::vector <Word> words;
};

#endif