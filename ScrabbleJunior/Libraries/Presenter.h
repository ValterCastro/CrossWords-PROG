#ifndef PRESENTER_H
#define PRESENTER_H

#include <iostream>
#include <string>
#include <vector>

#include "../Classes/Board.h"
#include "../Classes/Player.h"
#include "../Classes/Tile.h"
#include "ConsoleColorer.h"

// Responsible for presenting to user certain objects
class Presenter {
 public:
  Presenter();
  const char static SEPARATOR;

  void static presentBoardAndPlayers(Board board, std::vector<Player> players,
                                     unsigned short currentPlayerId);

 private:
  void static presentBoard(Board board);
  void static presentPlayer(Player player, bool isCorrentPlayer);
  std::string static navString(unsigned short nrCollumns);
  void static presentRow(unsigned short nrCollumns, char letter,
                         std::vector<Tile> rowTiles);
};

#endif