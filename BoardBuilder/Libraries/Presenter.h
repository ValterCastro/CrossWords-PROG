#ifndef PRESENTER_H
#define PRESENTER_H

#include <string>
#include <vector>
#include <set>

#include "Classes/Board.h"

// Responsible for presenting to user certain objects
class Presenter {
public:
    Presenter();
    const char static SEPARATOR;
    
    void static presentBoard(Board board);
private:
    std::string static navString(unsigned short nrCollumns);
    std::string static rowString(unsigned short nrCollumns, char letter, std::vector<char> rowTiles);
};

#endif