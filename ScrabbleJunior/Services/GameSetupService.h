#ifndef GAME_SETUP_SERVICE_H
#define GAME_SETUP_SERVICE_H

#include <string>
#include <vector>

#include "../Classes/Game.h"
#include "../Classes/Pool.h"
#include "../Classes/Word.h"
#include "../Libraries/Requester.h"
#include "BoardLoadService.h"
#include "PlayerFetchLettersService.h"
#include "PoolLoadService.h"

// Responsible for the initial Game setup.
class GameSetupService {
 public:
  GameSetupService();

  void static call(Game &game);
};

#endif
