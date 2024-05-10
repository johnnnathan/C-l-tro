#include "playingCard.h"
#include "tools.h"
#include <cstdint>
#include <string>

class Joker{
private:
  std::string desciption;
  uint8_t data;
public:
  int getActivatedOn();
  std::string getDescription();
  uint8_t getData();
  void setEdition(int edition);
  void setRarity(int rarity);
  void setActivateOn(int activation_code);
  Joker(int activation_code, int rarity, int edition);

};

void Joker::setEdition(int edition){
  if (edition < 1 || edition > 5){
    return;
  }
  int mask = int_to_hex(edition);
  data &= (0b111);
  data |= (mask << 5);

}
void Joker::setRarity(int rarity){
  if (rarity < 1||rarity > 4){
    return;
  }
  int mask = int_to_hex(rarity);
  data &= (0b11 << 2);
  data |= (mask << 2);
}
void Joker::setActivateOn(int activation_code){
  if (activation_code < 1 || activation_code > 5){
    return;
  }
  int mask = int_to_hex(activation_code);
  data &= (0b11 << 0);
  data |= (mask << 0);
}
