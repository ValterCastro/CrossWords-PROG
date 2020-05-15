#include "Presenter.h"

#include <iostream>
#include <string>
#include <vector>

#include "Classes/Board.h"

Presenter::Presenter() {};

const char Presenter::SEPARATOR = ' ';
const char Presenter::INITIAL_ROW_LETTER = 'A';
const char Presenter::INITIAL_COLLUMN_LETTER = 'a';

void Presenter::presentBoard(Board board){
    unsigned short nrRows;
    unsigned short nrCollumns;
    std::vector<std::vector<char>> boardTiles;
    std::string navString;
    std::string rowString;

    nrRows = board.getNrRows();
    nrCollumns = board.getNrCollumns();
    boardTiles = board.getTiles();
    navString = Presenter::navString(nrCollumns);

    std::cout << navString << '\n';
    for(size_t i = 0; i < nrRows; i++){
        rowString = Presenter::rowString(nrCollumns, Presenter::INITIAL_ROW_LETTER + i, boardTiles[i]);
        std::cout << rowString << '\n';
    }
    std::cout << '\n';
}

// private

std::string Presenter::navString(unsigned short nrCollumns){
    std::string collumnsNav;
    char letter;
 
    collumnsNav.push_back(Presenter::SEPARATOR);
    for(size_t i = 0; i < nrCollumns; i++){
        letter = Presenter::INITIAL_COLLUMN_LETTER + i;
        collumnsNav.push_back(letter);
        collumnsNav.push_back(Presenter::SEPARATOR);
    }
    
    return collumnsNav;
}

std::string Presenter::rowString(unsigned short nrCollumns, char letter, std::vector<char> rowTiles){
    std::string rowString;
    
    rowString.push_back(letter);

    for(size_t i = 0; i < nrCollumns; i++){
        rowString.push_back(rowTiles[i]);
        rowString.push_back(Presenter::SEPARATOR);
    }

    return rowString;
}