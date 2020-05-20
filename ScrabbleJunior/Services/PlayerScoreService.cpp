//
// Created by Administrator on 20/05/2020.
//

#include "PlayerScoreService.h"


void PlayerScoreService::call(Player &player, Tile &tile, Board &board){

    unsigned short score = player.getScore();

    std::vector<unsigned short> wordIds = tile.getWordIds();


    for(auto x: wordIds){
        
        Word w = board.getWord(x);

        if(w.getAvailableLetters().size() == 0)++score;

    }
    player.setScore(score);

}