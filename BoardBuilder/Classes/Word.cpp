#include "Word.h"

#include <string>
#include <cctype>

Word::Word(char position[2], WordOrientation orientation, std::string word) {
	this->position.push_back(position[0]);
	this->position.push_back(position[1]);
	this->orientation = orientation;
	this->word = Word::stringToUpper(word);
}

std::string Word::stringToUpper(std::string string){
	for(size_t i = 0; i <= string.size(); i++)
		string[i] = std::toupper(string[i]);

	return string;
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
