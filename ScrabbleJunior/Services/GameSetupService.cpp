#include "GameSetupService.h"

GameSetupService::GameSetupService(){};

void GameSetupService::call(Game &game) {
  unsigned short nrOfPlayers;
  std::string playerName;
  std::string boardFilename;

  // Setup Players
  nrOfPlayers = Requester::requestNrOfPlayers();
  for (size_t i = 0; i < nrOfPlayers; i++) {
    playerName = Requester::requestPlayerName(i + 1);
    game.addPlayer(Player::Player(i + 1, playerName));
  }

  // Setup Board
  boardFilename = Requester::requestBoardFilename();
  game.getBoard().setFilename(boardFilename);
  BoardLoadService::call(game.getBoard());
  PoolLoadService::call(game.getPool(), game.getBoard().getWords());

  // Draw Players Hands
  for (size_t i = 0; i < game.getPlayers().size(); i++) {
    PlayerFetchLettersService::call(game.getPlayers()[i], game.getPool());
  }
};