#include "Pool.h"

Pool::Pool(){};

void Pool::addToPool(char tileChar) { this->letters.push_back(tileChar); };

void Pool::shufflePool() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

  std::shuffle(this->letters.begin(), this->letters.end(),
               std::default_random_engine(seed));
};

char Pool::popCharFromPool() {
  char lastChar = this->letters.back();

  this->letters.pop_back();

  return lastChar;
};
