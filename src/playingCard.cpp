#include <cstdint>
#include <iostream>
#include <stdint.h>


class playingCard{
  private:
  unsigned short int data;//From left to right: Suit 2 bit/Rank 4 bits/ Enhancement 4 bits/ Edition 3 bits/ Seal 3 bits
  int8_t score;
  public:
  void setSuit(int8_t suit);
  void setRank(int8_t suit);
  void setEnhancement(int8_t suit);
  void setEdition(int8_t suit);
  void setSeal(int8_t suit);
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
    std::cerr << "SUIT VALUE NOT IN THE ACCEPTABLE RANGE, IS OUTSIDE OF [1,4]";
    return;
  }

}


