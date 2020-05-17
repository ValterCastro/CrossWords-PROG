#ifndef REQUESTER_H
#define REQUESTER_H

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "FileWrapper.h"

// Responsible for handling console requests to user
class Requester {
 public:
  Requester();

  unsigned short static requestNrOfPlayers();
  std::string static requestPlayerName(unsigned short playerId);
  std::string static requestBoardFilename();

  // OLD
  /*
  Word static requestWord(std::set<std::string> acceptableWords,
                          unsigned short nrRows, unsigned short nrCollumns);
  bool static requestIsBoardFinished();
  */
 private:
  int static getValidInt(std::string question, int min, int max);
  std::string static getNonBlankString(std::string question);
  std::string static getValidBoardFilename(std::string question);

  // OLD
  /*
  bool static getValidYesOrNo(std::string question);
  std::string static getValidWord(std::string question,
                                  std::set<std::string> acceptableWords);
  std::string static getValidPositionAndOrientation(std::string question,
                                                    unsigned short nrRows,
                                                    unsigned short nrCollumns);
*/
};

#endif