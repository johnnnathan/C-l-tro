#include <cstdint>
#include <stdint.h>
#include <string>
#include <iostream>
#include <cstdio>

int globalID {};
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

};

std::ostream& operator<<(std::ostream& os, const playingCard& card){
  os <<  "Rank: " << static_cast<int>(card.getRank()) 
     << " Suit: " << static_cast<int>(card.getSuit()) 
     << " Enhancement: " << static_cast<int>(card.getEnhancement())
     << " Edition: " << static_cast<int>(card.getEdition()) 
     << " Seal: " << static_cast<int>(card.getSeal());
  return os;
}


playingCard::playingCard(int8_t rank, int8_t suit, int8_t enhancement, int8_t edition, int8_t seal) {
    id = globalID; // Increment globalID and assign it to id
    globalID += 1;
    data = 0; // Initialize data
    setRank(rank);
    setSuit(suit);
    setEnhancement(enhancement);
    setEdition(edition);
    setSeal(seal);
}


int playingCard::getID(){
  return id;
}

void playingCard::setSuit(int8_t suit){
  if (suit > 4 || suit < 1){
    setError("SUIT",4);
    return;
  }
  int mask = int_to_hex(suit);
  data &= ~(0b11 << 14);
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
  data |= seal;
}


int8_t playingCard::getSuit() const{
  return (data >> 14) & 0b11;
}

int8_t playingCard::getRank() const{
    return (data >> 10) & 0b1111;
}

int8_t playingCard::getEnhancement() const{
    return (data >> 6) & 0b1111;
}

int8_t playingCard::getEdition() const{
    return (data >> 3) & 0b111;
}

int8_t playingCard::getSeal() const{
    return data & 0b111;
}



void setError(std::string valueType, int rangeEnd){
  printf("%s VALUE IS NOT IN THE ACCEPTABLE RANGE, IS OUTSIDE OF [1,%d]", valueType.c_str(),rangeEnd);
}



