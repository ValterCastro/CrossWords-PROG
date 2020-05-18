#ifndef WORD_H
#define WORD_H

#include <string>

class Word {
 public:
  Word(unsigned short id, std::string word);

  unsigned short getId() const;
  std::string getWord() const;
  std::vector<char> getAvailableLetters() const;
  char getFirstAvailableLetter() const;

  void removeAvailableLetter(char letter);

 private:
  unsigned short id;
  std::string word;
  std::vector<char> availableLetters;
};

#endif