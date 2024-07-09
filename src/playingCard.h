#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include <cstdint>
#include <stdint.h>
#include <string>
#include <iostream>
#include <cstdio>

const int8_t NO_ENHANCEMENT = 1;
const int8_t BONUS = 2;
const int8_t MULT = 3;
const int8_t WILD = 4;
const int8_t GLASS = 5;
const int8_t STEEL = 6;
const int8_t STONE = 7;
const int8_t GOLD = 8;
const int8_t LUCKY = 9;

const int8_t NO_EDITION = 1;
const int8_t FOIL = 2;
const int8_t HOLOGRAPHIC = 3;
const int8_t POLYCHROME = 4;

const int8_t NO_SEAL = 1;
const int8_t GOLD_SEAL = 2;
const int8_t RED_SEAL = 3;
const int8_t BLUE_SEAL = 4;
const int8_t PURPLE_SEAL = 5;

void setError(std::string valueType, int rangeEnd);
int int_to_hex(int value);
class playingCard{
  private:
  int id;
  unsigned short int data;//From left to right: Suit 2 bit/Rank 4 bits/ Enhancement 4 bits/ Edition 3 bits/ Seal 3 bits
  uint8_t score;
  public:
  void setSuit(int8_t suit);
  void setRank(int8_t rank);
  void setEnhancement(int8_t enhancement);
  void setEdition(int8_t edition);
  void setSeal(int8_t seal);
  void setScore(int8_t score);
  int getID();
  int8_t getSuit() const;
  int8_t getRank() const;
  int8_t getEnhancement() const;
  int8_t getEdition() const;
  int8_t getSeal() const;
  playingCard(int8_t rank, int8_t suit, int8_t enhancement, int8_t edition, int8_t seal);
  unsigned short int getData();
  friend std::ostream& operator<<(std::ostream& os, const playingCard& card);
  std::string toString() const;

};

#endif
