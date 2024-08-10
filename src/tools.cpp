#include "tools.h"
#include "jokerEffectProperties.h"
#include <cstdint>
#include <iostream>
#include <ostream>
#include <utility>

/* functions used as pointers in the Effect struct / joker class */
void add(int &basis, int effect) { basis = basis + effect; }
void subtract(int &basis, int effect) { basis = basis - effect; }
void multiply(int &basis, int effect) { basis = basis * effect; }
void divide(int &basis, int effect) {
  basis = effect != 0 ? basis / effect : 0;
}

/* detects if element is inside the given array*/
bool isIn(std::array<int, 5> array, int number) {
  bool flag = false;
  for (int i = 0; i < 5; i++) {
    if (array[i] == number) {
      flag = true;
      break;
    }
  }
  return flag;
}
std::string filterToString(Filter filter) {

  switch (filter) {
  case Filter::NONE:
    return "None";
  case Filter::EVEN:
    return "Even";
  case Filter::ODD:
    return "Odd";
  case Filter::HEARTS:
    return "Hearts";
  case Filter::CLUBS:
    return "Clubs";
  case Filter::SPADES:
    return "Spades";
  case Filter::DIAMONDS:
    return "Diamonds";
  case Filter::FACE:
    return "Face";
  case Filter::ACE:
    return "Ace";
  default:
    return "Unknown";
  }
}

std::string targetToString(Target target) {
  switch (target) {
  case Target::CHIPS:
    return "Chips";
  case Target::MULTIPLIER:
    return "Multiplier";
  case Target::MONEY:
    return "Money";
  default:
    return "Unknown";
  }
}

std::string operationToString(Operation operation) {
  switch (operation) {
  case Operation::ADD:
    return "ADD";
  case Operation::SUBTRACT:
    return "SUBTRACT";
  case Operation::MULTIPLY:
    return "MULTIPLY";
  case Operation::ADD_CARD:
    return "ADD_CARD";
  case Operation::GIVE_SCORE:
    return "GIVE_SCORE";
  case Operation::GIVE_ENHANCEMENT:
    return "GIVE_ENHANCEMENT";
  default:
    return "UNKNOWN";
  }
}
/* Same as isIn but for 5 elements instead of just one, could modify it to
 * accept an array with 5 or less elements, but not necessary for now */
bool areIn(std::array<int, 5> given, std::array<int, 5> wanted) {
  bool flag = true;
  for (int i = 0; i < 5; i++) {
    if (!isIn(given, wanted[i])) {
      flag = false;
      break;
    }
  }
  return flag;
}

/* Simple method to see whether or not the value given is greater than, or equal
 * to zero and at most the maximum value given */
bool checkRange(int max, int value) { return value >= 0 && value <= max; }

/* Logger method, error messages can and should be defined in the indidual
 * classes that use this */
void printError(std::string error) { std::cout << error << '\n'; }

/* Insertion sort method for a played hand, only works for full hands, meaning 5
 * played cards */
std::array<PlayingCard, 5> sortPlayingCards(std::array<PlayingCard, 5> array) {
  for (int i = 1; i < 5; i++) {
    PlayingCard card = array[i];
    int key = static_cast<int>(card.getRank());
    int j = i - 1;

    while (j >= 0 && key > static_cast<int>(array[j].getRank())) {
      std::swap(array[j], array[j + 1]);
      j -= 1;
    }
    array[j + 1] = card;
  }
  return array;
}

void setPoints(Points &points, int mult, int chips) {
  points.multiplier += mult;
  points.chips += chips;
}

/* set the bits of a variable, data is the template that gets operaterd upon,
 * value is the value that should be added to it, mask is used to determine the
 * amount of bits affected and shift determines which bits onwards get overriden
 */
template <typename T>
void setBits(T &data, int value, uint16_t mask, int shift) {
  data |= (value << shift) & mask;
}

/* clears the bits of the data object using the given mask */
template <typename T> void clearBits(T &data, uint16_t mask) { data &= ~mask; }

/* compiles the clearBits and setBits methods into one method */
template <typename T>
void clearAndSet(T &data, int value, uint16_t mask, int shift) {
  clearBits(data, mask);
  setBits(data, value, mask, shift);
}

template void clearAndSet<uint8_t>(uint8_t &data, int value, uint16_t mask,
                                   int shift);
template void clearAndSet<short int>(short int &data, int value, uint16_t mask,
                                     int shift);
template void clearAndSet<unsigned short>(unsigned short &data, int value,
                                          uint16_t mask, int shift);

template void clearBits<uint8_t>(uint8_t &data, uint16_t mask);
template void setBits<uint8_t>(uint8_t &data, int value, uint16_t mask,
                               int shift);

template void clearBits<short int>(short int &data, uint16_t mask);
template void setBits<short int>(short int &data, int value, uint16_t mask,
                                 int shift);

template void clearBits<unsigned short>(unsigned short &data, uint16_t mask);
template void setBits<unsigned short>(unsigned short &data, int value,
                                      uint16_t mask, int shift);
