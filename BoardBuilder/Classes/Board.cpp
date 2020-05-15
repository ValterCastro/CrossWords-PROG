#include "Board.h"

#include <string>
#include <vector>
#include "Word.h"

Board::Board() {}

// getters

std::string Board::getName() {
	return this->name;
}

unsigned short Board::getNrRows() {
	return this->tiles.size();
}

unsigned short Board::getNrCollumns() {
	return this->tiles[0].size();
}

std::vector<std::vector<char>> Board::getTiles() {
	return this->tiles;
}

std::vector<Word> Board::getWords() {
	return this->words;
}

// setters

void Board::setNrRows(unsigned short nrRows) {
	this->tiles.resize(nrRows);
}

void Board::setNrCollumns(unsigned short nrCollumns) {
	unsigned short nrRows;

	nrRows = this->getNrRows();
	for(size_t i = 0; i < nrRows; i++){
		this->tiles[i].resize(nrCollumns);
	}
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