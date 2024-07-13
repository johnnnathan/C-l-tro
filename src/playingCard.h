#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include <cstdint>
#include <stdint.h>
#include <string>
#include <iostream>
#include <cstdio>


const char NO_ENHANCEMENT = 1;
const char BONUS = 2;
const char MULT = 3;
const char WILD = 4;
const char GLASS = 5;
const char STEEL = 6;
const char STONE = 7;
const char GOLD = 8;
const char LUCKY = 9;

const char NO_SEAL = 1;
const char GOLD_SEAL = 2;
const char RED_SEAL = 3;
const char BLUE_SEAL = 4;
const char PURPLE_SEAL = 5;

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
