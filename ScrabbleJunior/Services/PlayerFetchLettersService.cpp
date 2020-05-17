#include "PlayerFetchLettersService.h"

PlayerFetchLettersService::PlayerFetchLettersService(){};

void PlayerFetchLettersService::call(Player &player, Pool &pool) {
  unsigned short currentHandSize = player.getHand().size();

  for (size_t i = 0; i < 7 - currentHandSize; i++) {
    char letter = pool.getLastLetter();
    if (letter == '\0') break;

    pool.popLastLetter();
    player.addLetter(letter);
  }
}