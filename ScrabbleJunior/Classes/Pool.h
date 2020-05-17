#ifndef POOL_H
#define POOL_H

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

class Pool {
 public:
  Pool();

  void addToPool(char tileChar);
  void shufflePool();
  char popCharFromPool();

 private:
  std::vector<char> letters;
};

#endif