#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>

class Player{
public:
    Player(unsigned int id, std::vector<char> hand,  unsigned int score);

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

#endif
