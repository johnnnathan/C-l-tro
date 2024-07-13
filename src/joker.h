#ifndef JOKER_H
#define JOKER_H

#define JOKER_H
#include <cstdint>
#include <string>

const std::string OUT_OF_RANGE_ERROR = "The given value is out of range";


const char EDITION_SHIFT = 4;
const char RARITY_SHIFT = 2;
const char ACTIVATION_SHIFT = 0;


const uint8_t EDITION_MASK = 0b111 << EDITION_SHIFT;
const uint8_t RARITY_MASK = 0b11 << RARITY_SHIFT;
const uint8_t ACTIVATION_CODE_MASK = 0b00000011;

const uint8_t BASE = 0;
class Joker{
private:
  std::string description;
  uint8_t data;
  public:
  void set(int min, int max, int value, int shift, uint8_t mask);
  void setDescription(std::string text);
  void setEdition(int edition);
  void setRarity(int rarity);
  void setActivateOn(int activation_code);

  void toString();

  std::string getDescription();
  uint8_t getData();
  int getEdition();
  int getRarity();
  int getActivatedOn();

  Joker(int activation_code, int rarity, int edition);
};

#endif // JOKER_H
