#ifndef GAME_H
#define GAME_H

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

#include "Board.h"
#include "Player.h"

class Game {
 public:
  Game();

  // getters
  Board getBoard();
  std::vector<Player> getPlayers();
  std::vector<char> getPool();
  unsigned short getTurn();
  bool getEnded();

  // setters & mutators
  void setBoard(Board board);
  void addPlayer(Player player);
  void addToPool(char tileChar);
  void shufflePool();
  char popCharFromPool();
  void incrementTurn();
  void setEnded(bool ended);

 private:
  Board board;
  std::vector<Player> players;
  std::vector<char> pool;
  unsigned short turn;
  bool ended;
};

#endif