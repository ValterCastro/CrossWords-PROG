#include <iostream>

#include "Classes/Board.cpp"
#include "Classes/Game.cpp"
#include "Classes/Player.cpp"
#include "Classes/Pool.cpp"
#include "Classes/Tile.cpp"
#include "Classes/Word.cpp"
#include "Libraries/ConsoleColorer.cpp"
#include "Libraries/FileWrapper.cpp"
#include "Libraries/Presenter.cpp"
#include "Libraries/Requester.cpp"
#include "Services/BoardLoadService.cpp"
#include "Services/GameSetupService.cpp"
#include "Services/PlayerFetchLettersService.cpp"
#include "Services/PoolLoadService.cpp"

using namespace std;

int main() {
  // Initialize Vars
  Game game;
  std::string moveString;
  std::string lastComment;

  GameSetupService::call(game);

  // Play Game:
  while (!game.getEnded()) {
    game.incrementTurn();
    Player currentPlayer = game.getCurrentPlayer();

    PlayerFetchLettersService::call(currentPlayer, game.getPool());

    if (currentPlayer.getHand().size() == 0) continue;

    Presenter::presentBoardAndPlayers(game.getBoard(), game.getPlayers(),
                                      currentPlayer.getId());

    while (true) {
      moveString = Requester::requestLetterAndPosition(
          currentPlayer.getName(), game.getBoard().getNrRows(),
          game.getBoard().getNrCollumns());

      if (game.getBoard().isMoveValid(moveString, currentPlayer.getHand()))
        break;
      else {
        cout << "Invalid letter or position, please try again.\n"
             << "Letter must be in hand, same as position and not played.\n"
             << "Letter must also be first available letter of the word and "
                "different words.\n\n";
      }
    }

    //     - While not_valid,
    //     - Calculate points_won and add to player's score
    //     - Remove used letters from player hand
    //    - Get next 2, 1 or 0 tiles from Pool according to availability
    //    (vector.back() & vector.pop_back()) and add them on Player's hand
    //     - Save moves into Board (putting to Tile.played to true, rendering it
    //     red)
    //     - Check if game ended (Game.board.tiles.each verify played=1 ||
    //     Players.each verify hand.size = 0)
  }

  // - Calculate & Announce the winner

  getline(cin, lastComment);
  return 0;
}