#include "PoolLoadService.h"

PoolLoadService::PoolLoadService(){};

void PoolLoadService::call(Pool &pool, std::vector<Word> words) {
  // add all letters to Pool
  for (size_t i = 0; i < words.size(); i++) {
    std::string word = words[i].getWord();
    for (size_t n = 0; n < word.size(); n++) {
      pool.addToPool(word[n]);
    }
  }

  pool.shufflePool();
};