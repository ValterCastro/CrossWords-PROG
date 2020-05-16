#ifndef WORD_H
#define WORD_H

#include <vector>
#include <string>

enum class WordOrientation { Horizontal, Vertical };

class Word {
public:
	Word(char position[2], WordOrientation orientation, std::string word);

	std::vector<char> getPosition();
	WordOrientation getOrientation();
	std::string getWord();
private:
	std::vector<char> position;
	WordOrientation orientation;
	std::string word;
};

#endif