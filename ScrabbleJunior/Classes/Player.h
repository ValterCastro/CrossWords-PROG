#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player {
 public:
  Player(unsigned short id, std::string name);

  unsigned short getID() const;
  std::string getName() const;
  unsigned short getScore() const;
  std::vector<char> getHand() const;

  void setScore(unsigned short score);
  void addTile(char tileChar);
  void removeTile(char tileChar);

 private:
  unsigned short id;
  std::string name;
  unsigned short score;
  std::vector<char> hand;
};

#endif
