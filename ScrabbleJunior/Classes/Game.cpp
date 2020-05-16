#include "Game.h"

Game::Game() {
  this->turn = 0;
  this->ended = false;
}

// getters
Board Game::getBoard() { return this->board; };

std::vector<Player> Game::getPlayers() { return this->players; };

std::vector<char> Game::getPool() { return this->pool; };

unsigned short Game::getTurn() { return this->turn; };

bool Game::getEnded() { return this->ended; };

// setters & mutators
void Game::setBoard(Board board) { this->board = board; };

void Game::addPlayer(Player player) { this->players.push_back(player); };

void Game::addToPool(char tileChar) { this->pool.push_back(tileChar); };

void Game::shufflePool() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

  std::shuffle(this->pool.begin(), this->pool.end(),
               std::default_random_engine(seed));
};

char Game::popCharFromPool() {
  char lastChar = this->pool.back();

  this->pool.pop_back();

  return lastChar;
};

void Game::incrementTurn() { this->turn++; };

void Game::setEnded(bool ended) { this->ended = ended; };