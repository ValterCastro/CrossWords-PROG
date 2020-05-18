#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Board.h"
#include "Player.h"
#include "Pool.h"

class Game {
 public:
  Game();

  // getters
  Board &getBoard();
  std::vector<Player> &getPlayers();
  Player &getCurrentPlayer();
  Pool &getPool();
  unsigned short getTurn() const;
  bool getEnded() const;

  // setters & mutators
  void setBoard(Board board);
  void addPlayer(Player player);
  void incrementTurn();
  void setEnded(bool ended);

 private:
  Board board;
  std::vector<Player> players;
  Pool pool;
  unsigned short turn;
  bool ended;
};

#endif