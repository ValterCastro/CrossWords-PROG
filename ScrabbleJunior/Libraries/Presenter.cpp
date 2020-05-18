#include "Presenter.h"

Presenter::Presenter(){};

const char Presenter::SEPARATOR = ' ';

void Presenter::presentBoardAndPlayers(Board board, std::vector<Player> players,
                                       unsigned short currentPlayerId) {
  Presenter::presentBoard(board);

  for (size_t i = 0; i < players.size(); i++) {
    bool isCurrentPlayer = players[i].getId() == currentPlayerId;
    Presenter::presentPlayer(players[i], isCurrentPlayer);
  }

  std::cout << '\n';
}

// private

void Presenter::presentBoard(Board board) {
  unsigned short nrRows;
  unsigned short nrCollumns;
  std::vector<std::vector<Tile>> boardTiles;
  std::string navString;
  std::string rowString;

  boardTiles = board.getTiles();
  nrRows = board.getNrRows();
  nrCollumns = board.getNrCollumns();

  navString = Presenter::navString(nrCollumns);

  std::cout << navString << '\n';
  for (size_t i = 0; i < nrRows; i++) {
    Presenter::presentRow(nrCollumns, Board::INITIAL_ROW_LETTER + i,
                          boardTiles[i]);
  }
  std::cout << '\n';
}

void Presenter::presentPlayer(Player player, bool isCurrentPlayer) {
  if (isCurrentPlayer) std::cout << '*';

  std::cout << player.getId() << ". " << player.getName() << " - "
            << player.getScore() << " points\n";
  std::cout << "HAND: ";
  for (size_t i = 0; i < player.getHand().size(); i++) {
    std::cout << player.getHand()[i] << Presenter::SEPARATOR;
  }
  std::cout << '\n';
}

std::string Presenter::navString(unsigned short nrCollumns) {
  std::string collumnsNav;
  char letter;

  collumnsNav.push_back(Presenter::SEPARATOR);
  for (size_t i = 0; i < nrCollumns; i++) {
    letter = Board::INITIAL_COLLUMN_LETTER + i;
    collumnsNav.push_back(letter);
    collumnsNav.push_back(Presenter::SEPARATOR);
  }

  return collumnsNav;
}

void Presenter::presentRow(unsigned short nrCollumns, char letter,
                           std::vector<Tile> rowTiles) {
  Tile tile;

  ConsoleColorer::setColorAndBackground(WHITE, BLACK);
  std::cout << letter;

  for (size_t i = 0; i < nrCollumns; i++) {
    tile = rowTiles[i];
    if (tile.getPlayed())
      ConsoleColorer::setColorAndBackground(RED, LIGHTGRAY);
    else
      ConsoleColorer::setColorAndBackground(BLACK, LIGHTGRAY);

    std::cout << tile.getLetter();

    // don't add separator on last collumn
    if (i != nrCollumns - 1) std::cout << Presenter::SEPARATOR;
  }

  ConsoleColorer::setColorAndBackground(WHITE, BLACK);
  std::cout << '\n';
}
