# Scrabble Junior & Board Builder

## Board Builder (Tiago)

### Important Assumptions
- Minimum size of the board? 5x5
- Amount of words on the board? user chooses (per turn after minimum of 5 words)
- How to check a position for a word is valid? From position, check iteratively each square, if occupied check is the same char.
- How to render the Board / positions every time? 2D vector with a for loop.

### Requisites / User Flow
- Ask and save Board.name (Extra: test that it saves well, proving valid file_name) (DONE)
- Ask and save Board.nrRows and Board.nrCollumns (from 5x5 to 20x20, accept any size between) (DONE)
- Word building process:
  - Load WORDS.TXT and save to set "words" (DONE)
  - Iteration until break
    - Render Board (DONE)
    - Ask for a word && check word exists in words (DONE)
    - Ask position and Horz/Vert (allow to restart iteration on "R") && check position is valid (DONE)
    - Update Board.board with new letters (DONE)
    - Save word in Board.words (DONE)
    - IF i > 5, Ask if they want to finish the Board (if "Y", break) (DONE)
- Create & save board file (respecting format) (DONE)

### Objects

Classes:
  - Board (Required):
    - .name string
    - .nrRows unsigned short
    - .nrCollumns unsigned short
    - .tiles vector [line][collumn]
    - .words vector Word
    
  - Word:
    - .position char[2]
    - .orientation (ENUM :horizontal, :vertical)
    - .word string

## Scrabble Junior (Valter)

### Important Assumptions
Who plays first? We will always assume it's Player 1, since it has no impact and was not required.
How to render all players tiles? Around the board, left-to-right & top-to-bottom.

### Requisites / User Flow
- The code must be structured in order to separate the definition of each class and the implementation of its methods, in files with the extension .hpp (or .h) and .cpp, respectively.

- Game Setup:
  - Ask nr of players (accept 2, 3, 4) (DONE)
  - Create X players (DONE)  
  - Ask each player names & save (DONE)
  
  - Ask which board they want to play & validate (DONE)
  - Save selected board filename (DONE)

- Board Prep:
  - Create Board (DONE)
  - Load selected board to Tiles & Words (DONE)  
  - Load selected board to Pool (slicing each char & then shuffling) (DONE)

- Play Game:
  While !game_ended:
    player = Game.players[Game.turn % nr_players]
    - Render selected board, each player tiles & score, and an * on the current active player
    - While not_valid, 
      - Ask which letter & position wants to play (example: A Cb) & validate format
      - IF player.letters > 1, Ask which letter & position wants to play (example: A Cb) & validate format
      - Validate moves: (letters_are_in_players_hand? && matches_available_letters && (lowest_possible_index? || (first_turn? && first_and_second_of_same_word?))
    - Calculate points_won and add to player's score
    - Remove used letters from player hand
    - Get next 2, 1 or 0 tiles from Pool according to availability (vector.back() & vector.pop_back()) and add them on Player's hand
    - Save moves into Board (putting to Tile.played to true, rendering it red) 
    - Check if game ended (Game.board.tiles.each verify played=1 || Players.each verify hand.size = 0)

- Calculate & Announce the winner

### Objects

Classes:
- Game
  - .board Board
  - .players vector Player
  - .pool Pool
  - .turn unsigned short
  - .ended bool

- Board
  - .filename string
  - .tiles vector [line][collumn] Tile
  - .words map[id] => [Word] 

- Player
  - .id unsigned short
  - .name string
  - .score unsigned short
  - .hand vector char

- Tile
  - .letter char /A-Z/
  - .played bool
  - .wordIds vector<unsigned short>

- Word
  - .id unsigned short
  - .word string
  - .nrLettersMissing unsigned short

- Pool
  - .letters vector<char>

Important Note: Google C++ code style was chosen and followed