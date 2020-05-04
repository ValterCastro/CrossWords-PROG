#include "Board.h"

#include <string>
#include <vector>
#include "Word.h"

Board::Board() {}

std::vector<unsigned short> Board::getSize() {
	return this->size;
}

std::string Board::getName() {
	return this->name;
}

std::vector<std::vector<char>> Board::getTiles() {
	return this->tiles;
}

std::vector<Word> Board::getWords() {
	return this->words;
}

void Board::setSize(unsigned short nr_rows, unsigned short nr_collumns) {
	std::vector<unsigned short> size;
	size.push_back(nr_rows);
	size.push_back(nr_collumns);

	this->size = size;
}

void Board::setName(std::string name) {
	this->name = name;
}

void Board::setTile(unsigned short row, unsigned short collumn, char letter) {
	this->tiles.at(row).at(collumn) = letter;
}

void Board::addWord(Word word) {
	this->words.push_back(word);
}