#include "Word.h"

Word::Word(unsigned short id, std::string word,
           unsigned short nrLettersMissing) {
  this->id = id;
  this->word = word;
  this->nrLettersMissing = nrLettersMissing;
};

unsigned short Word::getId() { return this->id; };

std::string Word::getWord() { return this->word; };

unsigned short Word::getNrLettersMissing() { return this->nrLettersMissing; };

void Word::decrementNrLettersMissing() { this->nrLettersMissing--; };