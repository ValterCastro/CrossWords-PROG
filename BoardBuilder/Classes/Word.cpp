#include "Word.h"

#include <string>

Word::Word(char position[2], WordOrientation orientation, std::string word) {
	this->position.push_back(position[0]);
	this->position.push_back(position[1]);
	this->orientation = orientation;
	this->word = word;
}

std::vector<char> Word::getPosition(){
	return this->position;
}

WordOrientation Word::getOrientation(){
	return this->orientation;
}

std::string Word::getWord(){
	return this->word;
}