#ifndef REQUESTER_H
#define REQUESTER_H

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "Classes/Word.h"
#include "FileWrapper.h"

// Responsible for handling console requests to user
class Requester {
 public:
  Requester();

  std::string static requestBoardName();
  std::vector<unsigned short> static requestBoardSize();
  Word static requestWord(std::set<std::string> acceptableWords,
                          unsigned short nrRows, unsigned short nrCollumns);
  bool static requestIsBoardFinished();

 private:
  std::string static getValidFilename(std::string question);
  int static getValidInt(std::string question, int min, int max);
  bool static getValidYesOrNo(std::string question);
  std::string static getValidWord(std::string question,
                                  std::set<std::string> acceptableWords);
  std::string static getValidPositionAndOrientation(std::string question,
                                                    unsigned short nrRows,
                                                    unsigned short nrCollumns);
};

#endif