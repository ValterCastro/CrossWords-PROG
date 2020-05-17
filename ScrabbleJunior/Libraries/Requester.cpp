#include "Requester.h"

Requester::Requester() {}

unsigned short Requester::requestNrOfPlayers() {
  unsigned short nrPlayers;
  std::string question;

  question = "How many players are you?";
  nrPlayers = Requester::getValidInt(question, 2, 4);
  std::cout << '\n';

  return nrPlayers;
}

std::string Requester::requestPlayerName(unsigned short playerId) {
  std::string playerName;
  std::string question;

  question = "What's the name of player nr " + std::to_string(playerId) + "?";
  playerName = Requester::getNonBlankString(question);
  std::cout << '\n';

  return playerName;
}

std::string Requester::requestBoardFilename() {
  std::string boardFilename;
  std::string question;

  question = "What is the name of the board you would like to load?";
  boardFilename = Requester::getValidBoardFilename(question);
  std::cout << '\n';

  return boardFilename;
}

// private

int Requester::getValidInt(std::string question, int min, int max) {
  bool valid_input = false;
  int answer;

  do {
    std::cout << question << '\n';
    std::cin >> answer;
    if (!std::cin.fail() && answer >= min && answer <= max) {
      valid_input = true;
      std::cin.ignore(1000, '\n');
    } else {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "Invalid input, please write a number between " << min
                << " and " << max << ".\n\n";
    }
  } while (!valid_input);

  return answer;
}

std::string Requester::getNonBlankString(std::string question) {
  bool valid_input = false;
  std::string answer;

  do {
    std::cout << question << '\n';
    getline(std::cin, answer);
    if (!answer.empty()) {
      valid_input = true;
    } else {
      std::cout << "Invalid input, blank not allowed.\n\n";
    }
  } while (!valid_input);

  return answer;
}

std::string Requester::getValidBoardFilename(std::string question) {
  bool valid_input = false;
  std::string answer;

  do {
    std::cout << question << '\n';
    getline(std::cin, answer);

    if (FileWrapper::isValidBoardFilename(answer + ".txt")) {
      valid_input = true;
    } else {
      std::cout << "Invalid input, please write a valid filename.\n\n";
    }
  } while (!valid_input);

  return answer + ".txt";
}

// OLD
/*

Word Requester::requestWord(std::set<std::string> acceptableWords,
                            unsigned short nrRows, unsigned short nrCollumns) {
  std::string question;
  std::string wordString;
  std::string positionAndOrientationString;
  WordOrientation orientation;

  question = "Which word you would like to add?";
  wordString = Requester::getValidWord(question, acceptableWords);
  std::cout << '\n';

  question = "And which position and orientation? (eg: 'Ca H' or 'Ab V')";
  positionAndOrientationString =
      Requester::getValidPositionAndOrientation(question, nrRows, nrCollumns);
  std::cout << '\n';

  char position[2] = {positionAndOrientationString[0],
                      positionAndOrientationString[1]};
  orientation = positionAndOrientationString[3] == 'H'
                    ? WordOrientation::Horizontal
                    : WordOrientation::Vertical;
  Word word(position, orientation, wordString);

  return word;
}

bool Requester::requestIsBoardFinished() {
  bool boardFinished;

  boardFinished =
      !Requester::getValidYesOrNo("Would you like to add another word?");
  std::cout << '\n';

  return boardFinished;
}

// Private


bool Requester::getValidYesOrNo(std::string question) {
  bool valid_input = false;
  std::string answer;

  do {
    std::cout << question << '\n';
    getline(std::cin, answer);
    if (answer == "Y" || answer == "Yes" || answer == "yes" || answer == "N" ||
        answer == "No" || answer == "no")
      valid_input = true;
    else {
      std::cout << "Invalid input, please write Y/Yes or N/No.\n\n";
    }
  } while (!valid_input);

  return (answer == "Y" || answer == "Yes" || answer == "yes");
}

std::string Requester::getValidWord(std::string question,
                                    std::set<std::string> acceptableWords) {
  bool valid_input = false;
  std::string answer;

  do {
    std::cout << question << '\n';
    getline(std::cin, answer);
    if (acceptableWords.find(answer) != acceptableWords.end())
      valid_input = true;
    else {
      std::cout << "Word not found in WORDS.TXT, please write a word from that "
                   "file.\n\n";
    }
  } while (!valid_input);

  return answer;
}

std::string Requester::getValidPositionAndOrientation(
    std::string question, unsigned short nrRows, unsigned short nrCollumns) {
  bool valid_input = false;
  std::string answer;
  char maxRowLetter;
  char maxCollumnLetter;

  maxRowLetter = Board::INITIAL_ROW_LETTER + (nrRows - 1);
  maxCollumnLetter = Board::INITIAL_COLLUMN_LETTER + (nrCollumns - 1);

  do {
    std::cout << question << '\n';
    getline(std::cin, answer);

    if (answer[0] <= maxRowLetter && answer[1] <= maxCollumnLetter &&
        answer[2] == ' ' && (answer[3] == 'H' || answer[3] == 'V'))
      valid_input = true;
    else {
      std::cout << "Invalid input, please write a valid position and "
                   "orientation.\n\n";
    }
  } while (!valid_input);

  return answer;
} */