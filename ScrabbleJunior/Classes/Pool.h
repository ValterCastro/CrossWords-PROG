#ifndef POOL_H
#define POOL_H

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

class Pool {
 public:
  Pool();

  char getLastLetter() const;

  void addToPool(char tileChar);
  void shufflePool();
  void popLastLetter();

 private:
  std::vector<char> letters;
};

#endif