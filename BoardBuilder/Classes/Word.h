#ifndef WORD_H
#define WORD_H

#include <string>

enum class WordOrientation { Horizontal, Vertical };

class Word {
public:
	Word(char position[2], WordOrientation orientation, std::string word);

private:
	char position[2];
	WordOrientation orientation;
	std::string word;
};

#endif