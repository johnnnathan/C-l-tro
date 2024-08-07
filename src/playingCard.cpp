#include "playingCard.h"
#include "cardProperties.h"
#include "tools.h"
#include <iomanip>
#include <sstream>

int globalID{1};
const int SUIT_SHIFT = 14;
const int RANK_SHIFT = 10;
const int ENHANCEMENT_SHIFT = 6;
const int EDITION_SHIFT = 3;
const int SEAL_SHIFT = 0;

const uint16_t BIT_2MASK = 0x3; // 2-bit mask
const uint16_t BIT_3MASK = 0x7; // 3-bit mask
const uint16_t BIT_4MASK = 0xF; // 4-bit mask

int getGlobalID() { return globalID; }

void resetGlobalID() { globalID = 1; }

/* Method to generate a random color for the toString method, making it simpler
 * to read when put next to multiple other toString results */
std::string getRandomColorCode() {
  const std::string colors[] = {
      "\033[31m", // Red
      "\033[32m", // Green
      "\033[33m", // Yellow
      "\033[34m", // Blue
      "\033[35m", // Magenta
      "\033[36m", // Cyan
  };
  int randomIndex = rand() % 6;
  return colors[randomIndex];
}
/* toString implementation of playingCard object */
std::string PlayingCard::toString() const {
  // Maximum widths for each attribute
  const int ID_WIDTH = 2;
  const int RANK_WIDTH = 15;
  const int SUIT_WIDTH = 10;
  const int ENHANCEMENT_WIDTH = 15;
  const int EDITION_WIDTH = 15;
  const int SEAL_WIDTH = 15;

  std::stringstream ss;
  ss << getRandomColorCode() << "ID: " << std::setw(ID_WIDTH)
     << std::setfill(' ') << getID() << "  Rank: " << std::setw(RANK_WIDTH)
     << std::setfill(' ') << rankToString(getRank())
     << "  Suit: " << std::setw(SUIT_WIDTH) << std::setfill(' ')
     << suitToString(getSuit())
     << "  Enhancement: " << std::setw(ENHANCEMENT_WIDTH) << std::setfill(' ')
     << enhancementToString(getEnhancement())
     << "  Edition: " << std::setw(EDITION_WIDTH) << std::setfill(' ')
     << editionToString(getEdition()) << "  Seal: " << std::setw(SEAL_WIDTH)
     << std::setfill(' ') << sealToString(getSeal()) << "\033[0m";
  return ss.str();
}
/* override of << operator, to allow cards to be printed */
std::ostream &operator<<(std::ostream &os, const PlayingCard &card) {
  os << card.toString();
  return os;
}

/* Uses the toString method to print the card, qol not needed */
void PlayingCard::print() {
  std::string result = toString();
  std::cout << result << '\n';
}

/* Constructor for PlayingCard object using the cardProperties Header */
PlayingCard::PlayingCard(Rank rank, Suit suit, Enhancement enhancement,
                         Edition edition, Seal seal) {

  id = globalID; // Increment globalID and assign it to id
  globalID += 1;
  data = 0; // Initialize data

  setRank(rank);
  setSuit(suit);
  setEnhancement(enhancement);
  setEdition(edition);
  setSeal(seal);
}

PlayingCard::PlayingCard(int zero) {
  id = 0;
  data = 0;
  setRank(Rank::ERROR);
  setSuit(Suit::HEARTS);
  setEnhancement(Enhancement::NO_ENHANCEMENT);
  setEdition(Edition::NO_EDITION_CARD);
  setSeal(Seal::NO_SEAL);
}
/* Interface impmentation for the bitwise operations, the same as the one found
 * in the joker class */
void PlayingCard::set(int max, int value, int shift, uint16_t mask) {
  if (!checkRange(max, value)) {
    printError("Value out of range");
    return;
  }
  clearAndSet(data, value, mask << shift, shift);
}

void PlayingCard::setSuit(Suit suit) {
  set(3, static_cast<int8_t>(suit), SUIT_SHIFT, BIT_2MASK);
}

void PlayingCard::setRank(Rank rank) {
  set(13, static_cast<int8_t>(rank), RANK_SHIFT, BIT_4MASK);
}

void PlayingCard::setEnhancement(Enhancement enhancement) {
  set(8, static_cast<int8_t>(enhancement), ENHANCEMENT_SHIFT, BIT_4MASK);
}

void PlayingCard::setEdition(Edition edition) {
  set(3, static_cast<int8_t>(edition), EDITION_SHIFT, BIT_3MASK);
}

void PlayingCard::setSeal(Seal seal) {
  set(4, static_cast<int8_t>(seal), SEAL_SHIFT, BIT_3MASK);
}

/*
The following methods are getters, the type of data that they return is in the
name, no explanation needed for the calls Each method takes the offset given by
the respective shift amount and then isolates the needed bits using the &
operator with the mask
*/

int PlayingCard::getID() const { return id; }

Suit PlayingCard::getSuit() const {
  return static_cast<Suit>((data >> SUIT_SHIFT) & BIT_2MASK);
}

Rank PlayingCard::getRank() const {
  return static_cast<Rank>((data >> RANK_SHIFT) & BIT_4MASK);
}

Enhancement PlayingCard::getEnhancement() const {
  return static_cast<Enhancement>((data >> ENHANCEMENT_SHIFT) & BIT_4MASK);
}

Edition PlayingCard::getEdition() const {
  return static_cast<Edition>((data >> EDITION_SHIFT) & BIT_3MASK);
}

Seal PlayingCard::getSeal() const {
  return static_cast<Seal>(data & BIT_3MASK);
}
