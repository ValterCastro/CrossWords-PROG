#ifndef POOL_LOAD_SERVICE_H
#define POOL_LOAD_SERVICE_H

#include <string>
#include <vector>

#include "../Classes/Pool.h"
#include "../Classes/Word.h"

// Responsible for setting up Pool letters and its randomization
class PoolLoadService {
 public:
  PoolLoadService();

  void static call(Pool &pool, std::vector<Word> words);
};

#endif
