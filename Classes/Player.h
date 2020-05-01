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
    Player(unsigned int id, unsigned int score = 0, std::vector<char> hand);

    void getID() const;
    void getScore() const;
    void getHand() const;

    unsigned int setID(unsigned int id);
    unsigned int setScore(unsigned int score);
    std::vector<char> setHand(std::vector<char> hand);

private:
    unsigned int id;
    unsigned int score;
    std::vector<char> hand;
};

#endif //SCRABBLEJUNIOR_PLAYER_H
