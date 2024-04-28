#include <cstdint>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <stdint.h>


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
  unsigned short int data;//From left to right: Suit 2 bit/Rank 4 bits/ Enhancement 4 bits/ Edition 3 bits/ Seal 3 bits
  uint8_t score;
  public:
  void setSuit(int8_t suit);
  void setRank(int8_t rank);
  void setEnhancement(int8_t enhancement);
  void setEdition(int8_t edition);
  void setSeal(int8_t seal);
  void setScore(int8_t score);
  int8_t getSuit();
  int8_t getRank();
  int8_t getEnhancement();
  int8_t getEdition();
  int8_t getSeal();
  playingCard(int8_t rank, int8_t suit, int8_t enhancement, int8_t edition, int8_t seal);

};

void playingCard::setSuit(int8_t suit){
  if (suit > 4 || suit < 1){
    setError("SUIT",4);
    return;
  }
  int mask = int_to_hex(suit);
  data |= (mask << 14); 
}

void playingCard::setRank(int8_t rank){
  if (rank > 13 || rank < 1){
    setError("RANK", 13);
    return;
  }
  int mask = int_to_hex(rank);
  data &= ~(0b1111 << 10);
  data |= (mask << 10);

}

void playingCard::setEnhancement(int8_t enhancement){
  if (enhancement > 9 || enhancement < 1){
    setError("ENHANCEMENT",9);
    return;
  }
  int mask = int_to_hex(enhancement);
  data&= ~(0b1111 << 6);
  data |= (mask << 6);
}

void playingCard::setEdition(int8_t edition){
  if (edition < 1 || edition > 4){
    setError("EDITION",4);
    return;
  }
  int mask = int_to_hex(edition);
  data &= ~(0b111 << 3);
  data |= (edition << 3);
}
void playingCard::setSeal(int8_t seal){
  if (seal < 1 || seal > 5){
    setError("SEAL",5);
    return;
  }
  
  int mask = int_to_hex(seal);
  data &= ~(0b111 << 0);
  data |= (seal << 3);
}

void setError(std::string valueType, int rangeEnd){
  printf("%s VALUE IS NOT IN THE ACCEPTABLE RANGE, IS OUTSIDE OF [1,%d]", valueType.c_str(),rangeEnd);
}


int int_to_hex(int value){
  std::stringstream ss;
  ss << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(value);
  std::string hexString = ss.str();
  int mask;
  std::istringstream(hexString) >> std::hex >> mask;
  return mask;
}

