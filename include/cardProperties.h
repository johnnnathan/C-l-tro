#ifndef CARD_PROPERTIES_H
#define CARD_PROPERTIES_H

#include <cstdint>
enum class Rank : int8_t {
  TWO = 2,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK = 10,
  QUEEN = 10,
  KING = 10,
  ACE = 11,
};

enum class Suit : int8_t {
  HEARTS,
  CLUBS,
  DIAMONDS,
  SPADES,
};

enum class Seal : int8_t {
  NO_SEAL,
  GOLD_SEAL,
  RED_SEAL,
  BLUE_SEAL,
  PURPLE_SEAL,

};

enum class Enhancement : int8_t {
  NO_ENHANCEMENT,
  BONUS,
  MULT,
  WILD,
  GLASS,
  STEEL,
  STONE,
  GOLD,
  LUCKY,
};

enum class Edition : int8_t {
  NO_EDITION_CARD,
  FOIL,
  HOLOGRAPHIC,
  POLYCHROME,
};
#endif // !CARD_PROPERTIES_H
