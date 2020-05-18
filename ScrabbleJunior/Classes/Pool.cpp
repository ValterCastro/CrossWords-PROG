#include "Pool.h"

Pool::Pool(){};

char Pool::getLastLetter() const {
  char letter;
  if (this->letters.size() != 0)
    letter = this->letters.back();
  else
    letter = '\0';

  return letter;
}

void Pool::addToPool(char tileChar) { this->letters.push_back(tileChar); };

void Pool::shufflePool() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

  std::shuffle(this->letters.begin(), this->letters.end(),
               std::default_random_engine(seed));
};

void Pool::popLastLetter() { this->letters.pop_back(); };