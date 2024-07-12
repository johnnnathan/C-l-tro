#ifndef JOKER_H
#define JOKER_H

#define JOKER_H
#include <cstdint>
#include <string>

const uint8_t EDITION_MASK = 0b11100000;
const uint8_t RARITY_MASK = 0b00001100;
const uint8_t ACTIVATION_CODE_MASK = 0b00000011;

class Joker{
private:
  std::string description;
  uint8_t data;
public:
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
