#ifndef WORD_H
#define WORD_H

#include <string>

class Word {
 public:
  Word(unsigned short id, std::string word, unsigned short nrLettersMissing);

  unsigned short getId();
  std::string getWord();
  unsigned short getNrLettersMissing();

  void decrementNrLettersMissing();

 private:
  unsigned short id;
  std::string word;
  unsigned short nrLettersMissing;
};

#endif