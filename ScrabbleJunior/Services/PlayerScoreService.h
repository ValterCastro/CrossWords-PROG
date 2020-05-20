//
// Created by Administrator on 20/05/2020.
//

#ifndef SCRABBLEJUNIOR_PLAYERSCORESERVICE_H
#define SCRABBLEJUNIOR_PLAYERSCORESERVICE_H

#include <string>
#include <vector>

#include "../Classes/Player.h"
#include "../Classes/Tile.h"
#include "../Classes/Word.h"
#include "../Classes/Board.h"

class PlayerScoreService{
public:

    void static call(Player &player, Tile &tile, Board &board);

#endif //SCRABBLEJUNIOR_PLAYERSCORESERVICE_H
