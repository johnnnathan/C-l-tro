#ifndef JOKER_H
#define JOKER_H

#include "deck.h"
#include "jokerEffectProperties.h"
#include "playingCard.h"
#include "points.h"
#include <cstdint>
#include <string>

// Map to associate Operation enum with function pointers

const std::string OUT_OF_RANGE_ERROR = "The given value is out of range";

const char EDITION_SHIFT = 4;
const char RARITY_SHIFT = 2;
const char ACTIVATION_SHIFT = 0;

const uint8_t EDITION_MASK = 0b111 << EDITION_SHIFT;
const uint8_t RARITY_MASK = 0b11 << RARITY_SHIFT;
const uint8_t ACTIVATION_CODE_MASK = 0b00000011;

const char COMMON = 0;
const char UNCOMMON = 1;
const char RARE = 2;
const char LEGENDARY = 3;

const char ON_PLAYED = 0;
const char ON_SCORED = 1;
const char ON_HELD = 2;
const char ON_INDEPENDENT = 3;

const char NO_EDITION = 0;
const char FOIL = 1;
const char HOLOGRAPHIC = 2;
const char POLYCHROME = 3;
const char NEGATIVE = 4;

const char MAX_2BIT = 3;
const char MAX_3BIT = 5;

const uint8_t BASE = 0;

class Joker {
private:
  std::string name;
  std::string description;
  uint8_t data;
  Effect effect;
  std::function<void(int &, int)> func;

  int getFilterType();
  bool evaluateFilter(PlayingCard *card, int type);

  std::string generateName(Operation operation, Target target, int rarity);

  std::string generateDescription(Operation operation, Target target,
                                  Filter filter, int quantity);

public:
  void operate(PlayingCard *card, int &money, Points &points, Deck &deck);
  void set(int max, int value, int shift, uint8_t mask);
  void setDescription(std::string text);
  void setName(std::string value);
  void setEdition(int edition);
  void setRarity(int rarity);
  void setActivateOn(int activation_code);
  void setEffect(Effect effectTBA);

  void toString();

  std::string getDescription();
  std::string getName();
  uint8_t getData();
  int getEdition();
  int getRarity();
  int getActivatedOn();
  std::string getEffect();

  Joker(int activation_code, int rarity, int edition, Effect effectTBA);
  Joker();
};

#endif // JOKER_H
