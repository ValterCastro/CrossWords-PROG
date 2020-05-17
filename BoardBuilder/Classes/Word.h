#ifndef WORD_H
#define WORD_H

#include <string>
#include <vector>

enum class WordOrientation { Horizontal, Vertical };

class Word {
 public:
  Word(char position[2], WordOrientation orientation, std::string word);

  std::vector<char> getPosition() const;
  WordOrientation getOrientation() const;
  std::string getWord() const;
  std::string static stringToUpper(std::string string);

 private:
  std::vector<char> position;
  WordOrientation orientation;
  std::string word;
};

#endif