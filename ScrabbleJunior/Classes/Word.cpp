#include "Word.h"

Word::Word(unsigned short id, std::string word) {
  this->id = id;
  this->word = word;
  for (size_t i = 0; i < word.size(); i++) {
    this->availableLetters.push_back(word[i]);
  }
};

unsigned short Word::getId() const { return this->id; };

std::string Word::getWord() const { return this->word; };

std::vector<char> Word::getAvailableLetters() const {
  return this->availableLetters;
};

char Word::getFirstAvailableLetter() const {
  return this->availableLetters.front();
};

void Word::removeAvailableLetter(char letter) {
  std::vector<char>::iterator it;

  it = std::find(this->availableLetters.begin(), this->availableLetters.end(),
                 letter);
  if (it != this->availableLetters.end()) this->availableLetters.erase(it);
};