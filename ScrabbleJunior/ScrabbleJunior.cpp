#include <iostream>

#include "Classes/Board.cpp"
#include "Classes/Game.cpp"
#include "Classes/Player.cpp"
#include "Classes/Pool.cpp"
#include "Classes/Tile.cpp"
#include "Classes/Word.cpp"
#include "Libraries/BoardLoadService.cpp"
#include "Libraries/FileWrapper.cpp"
#include "Libraries/PoolLoadService.cpp"
#include "Libraries/Requester.cpp"

using namespace std;

int main() {
  // Initialize Vars
  Game game;
  unsigned short nrOfPlayers;
  std::string playerName;
  std::string boardFilename;

  // Game Setup
  // - Setup Players
  nrOfPlayers = Requester::requestNrOfPlayers();
  for (size_t i = 0; i < nrOfPlayers; i++) {
    playerName = Requester::requestPlayerName(i + 1);
    game.addPlayer(Player::Player(i + 1, playerName));
  }

  // - Setup Board
  boardFilename = Requester::requestBoardFilename();
  game.getBoard().setFilename(boardFilename);
  BoardLoadService::call(game.getBoard());
  PoolLoadService::call(game.getPool(), game.getBoard().getWords());

  cout << "line";

  // - Play Game:
  //   While !game_ended:
  //     player = Game.players[Game.turn % nr_players]
  //     - Render selected board, each player tiles & score, and an * on the
  //     current active player
  //     - While not_valid,
  //       - Ask which letter & position wants to play (example: A Cb) &
  //       validate format
  //       - IF player.letters > 1, Ask which letter & position wants to play
  //       (example: A Cb) & validate format
  //       - Validate moves: (letters_are_in_players_hand? &&
  //       matches_available_letters && (lowest_possible_index? || (first_turn?
  //       && first_and_second_of_same_word?))
  //     - Calculate points_won and add to player's score
  //     - Remove used letters from player hand
  //    - Get next 2, 1 or 0 tiles from Pool according to availability
  //    (vector.back() & vector.pop_back()) and add them on Player's hand
  //     - Save moves into Board (putting to Tile.played to true, rendering it
  //     red)
  //     - Check if game ended (Game.board.tiles.each verify played=1 ||
  //     Players.each verify hand.size = 0)
  //
  // - Calculate & Announce the winner

  getline(cin, playerName);
  return 0;
}