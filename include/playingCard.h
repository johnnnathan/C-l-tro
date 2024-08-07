#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include "cardProperties.h"
#include <cstdint>
#include <iostream>
#include <string>

void setError(std::string valueType, int rangeEnd);
int getGlobalID();
void resetGlobalID();

class PlayingCard {
private:
  int id;
  unsigned short int data; // From left to right: Suit 2 bits / Rank 4 bits /
                           // Enhancement 4 bits / Edition 3 bits / Seal 3 bits
  uint8_t score;

public:
  void setSuit(Suit suit);
  void setRank(Rank rank);
  void setEnhancement(Enhancement enhancement);
  void setEdition(Edition edition);
  void setSeal(Seal seal);
  void setScore(int8_t score);
  void set(int max, int value, int shift, uint16_t mask);

  int getID() const;
  Suit getSuit() const;
  Rank getRank() const;
  Enhancement getEnhancement() const;
  Edition getEdition() const;
  Seal getSeal() const;

  PlayingCard() : id(-1) {} // Default constructo
  PlayingCard(int zero);
  PlayingCard(Rank rank, Suit suit, Enhancement enhancement, Edition edition,
              Seal seal);

  unsigned short int getData();
  friend std::ostream &operator<<(std::ostream &os, const PlayingCard &card);
  std::string toString() const;
  void print();
};

#endif
