#include <iostream>

#include "Classes/Board.cpp"
#include "Classes/Game.cpp"
#include "Classes/Player.cpp"
#include "Classes/Tile.cpp"
#include "Classes/Word.cpp"

using namespace std;

int main() {
  std::string devComment;

  cout << "Game Started";

  Game game;

  game.addToPool('a');
  game.addToPool('b');
  game.addToPool('c');
  game.addToPool('d');
  game.addToPool('e');
  game.addToPool('f');
  game.addToPool('g');

  game.shufflePool();

  cout << "Finished";

  // - Game Setup:
  //   - Ask nr of players (accept 2, 3, 4)
  //   - Create X players
  //   - Ask each player names
  //     - save name
  //
  //   - Load available file/board names
  //   - Ask to select which board they want to play
  //   - Save selected file name
  //
  // - Board Prep:
  //   - Create Board
  //   - Load selected board to positions
  //   - Load selected board to Pool (slicing each char & then shuffling)
  //
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

  getline(cin, devComment);
  return 0;
}