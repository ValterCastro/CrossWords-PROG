#include "Game.h"

Game::Game() {
  this->turn = 0;
  this->ended = false;
}

// getters
Board &Game::getBoard() { return this->board; };

std::vector<Player> &Game::getPlayers() { return this->players; };

Player &Game::getCurrentPlayer() {
  return this->players[((this->turn - 1) % this->players.size())];
};

Pool &Game::getPool() { return this->pool; };

unsigned short Game::getTurn() const { return this->turn; };

bool Game::getEnded() const { return this->ended; };

// setters & mutators
void Game::setBoard(Board board) { this->board = board; };

void Game::addPlayer(Player player) { this->players.push_back(player); };

void Game::incrementTurn() { this->turn++; };

void Game::setEnded(bool ended) { this->ended = ended; };