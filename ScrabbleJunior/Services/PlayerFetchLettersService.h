#ifndef PLAYER_FETCH_LETTERS_SERVICE_H
#define PLAYER_FETCH_LETTERS_SERVICE_H

#include <string>
#include <vector>

#include "../Classes/Player.h"
#include "../Classes/Pool.h"

// Responsible for fetching letters from Pool to Player's Hand
class PlayerFetchLettersService {
 public:
  PlayerFetchLettersService();

  void static call(Player &player, Pool &pool);
};

#endif
