//
// Created by Administrator on 29/04/2020.
//

#ifndef SCRABBLEJUNIOR_PLAYER_H
#define SCRABBLEJUNIOR_PLAYER_H

#include <iostream>
#include <vector>
#include <string>

class Player{
public:
    Player(unsigned int id, std::vector<char> hand,  unsigned int score = 0);

    unsigned int getID() const;
    unsigned int getScore() const;
    std::vector<char> getHand() const;

    void setID(unsigned int id);
    void setScore(unsigned int score);
    void setHand(std::vector<char> hand);

private:
    unsigned int id;
    unsigned int score;
    std::vector<char> hand;
};

#endif //SCRABBLEJUNIOR_PLAYER_H
