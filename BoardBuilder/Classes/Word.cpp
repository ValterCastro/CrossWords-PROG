#include "Word.h"

#include <string>

Word::Word(char position[2], WordOrientation orientation, std::string word) {
	this->position = position;
	this->orientation = orientation;
	this->word = word;
}