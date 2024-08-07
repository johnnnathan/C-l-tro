#ifndef CARD_PROPERTIES_H
#define CARD_PROPERTIES_H

#include <cstdint>
#include <string>
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
  ACE,
  JACK,
  QUEEN,
  KING,
  ERROR = -1,
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

inline std::string rankToString(Rank rank) {
  static const char *const rankStrings[] = {
      "TWO",  "THREE", "FOUR", "FIVE",  "SIX",  "SEVEN", "EIGHT",
      "NINE", "TEN",   "JACK", "QUEEN", "KING", "ACE",   "ERROR"};
  return rankStrings[static_cast<int8_t>(rank)];
}

inline std::string suitToString(Suit suit) {
  static const char *const suitStrings[] = {"HEARTS", "CLUBS", "DIAMONDS",
                                            "SPADES"};
  return suitStrings[static_cast<int8_t>(suit)];
}

inline std::string enhancementToString(Enhancement enhancement) {
  static const char *const enhancementStrings[] = {
      "NO_ENHANCEMENT", "BONUS", "MULT", "WILD", "GLASS",
      "STEEL",          "STONE", "GOLD", "LUCKY"};
  return enhancementStrings[static_cast<int8_t>(enhancement)];
}

inline std::string editionToString(Edition edition) {
  static const char *const editionStrings[] = {"NO_EDITION_CARD", "FOIL",
                                               "HOLOGRAPHIC", "POLYCHROME"};
  return editionStrings[static_cast<int8_t>(edition)];
}

inline std::string sealToString(Seal seal) {
  static const char *const sealStrings[] = {"NO_SEAL", "GOLD_SEAL", "RED_SEAL",
                                            "BLUE_SEAL", "PURPLE_SEAL"};
  return sealStrings[static_cast<int8_t>(seal)];
}

#endif // !CARD_PROPERTIES_H
