#include "Word.h"

#include <string>

Word::Word(char position[2], WordOrientation orientation, std::string word) {
	this->position[0] = position[0];
	this->position[1] = position[1];
	this->orientation = orientation;
	this->word = word;
}