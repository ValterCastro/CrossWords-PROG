#include "Board.h"

#include <string>
#include <vector>
#include "Word.h"

Board::Board() {}

std::vector<unsigned short> Board::getSize() {
	return size;
}

std::string Board::getName() {
	return name;
}

std::vector<std::vector> Board::getTiles() {
	return tiles;
}

std::vector<Word> Board::getWords() {
	return words;
}

Board::setSize(unsigned short nr_rows, unsigned short nr_collumns) {
	this->size[0] = nr_rows;
	this->size[1] = nr_collumns;
}

Board::setName(std::string name) {
	this->name = name;
}

Board::setTile(unsigned short row, unsigned short collumn, char letter) {
	this->tiles.at(row).at(collumn) = letter;
}

Board::addWord(Word word) {
	this->words.push_back(word);
}