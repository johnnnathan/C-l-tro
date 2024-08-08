#include "joker.h"
#include "jokerEffectProperties.h"
#include <cstdint>
#include <functional>
#include <i386/limits.h>

/* Joker constructor */
Joker::Joker(int activation_code, int rarity, int edition) {
  data = 0;
  setRarity(rarity);
  setActivateOn(activation_code);
  setEdition(edition);
}

/*

Note: This method is pretty much the implementation of the Interface Pattern,
Instead of adding the same code into each of the setters I use this one to
handle them all.

Parameters:
  int max: the max value that the value parameter can take, used in the
checkRange method int value: the value that I want to add to the data of the
object int shift: handles the position of the value in the data object, each
type has their own potition and legal range uint8_t mask: the mask that is use
to nullify the range of the value in data so that no errors happen during value
assignment

Desciption:
  check the range of the value object using max, starts from 0 in each case
  use the clearAndSet method call to handle the rest, is universal tool

*/
void Joker::set(int max, int value, int shift, uint8_t mask) {
  if (!checkRange(max, value)) {
    printError(OUT_OF_RANGE_ERROR);
    return;
  }
  clearAndSet(data, value, mask, shift);
}

/* getter for Joker Description */
std::string Joker::getDescription() { return description; }

/* getter for Joker Name */
std::string Joker::getName() { return name; }

/* getter for Joker Edition */
int Joker::getEdition() { return (data >> EDITION_SHIFT) & 0b111; }

/* getter for Joker Rarity */
int Joker::getRarity() { return (data >> RARITY_SHIFT) & 0b11; }

/* getter for Activation Code */
int Joker::getActivatedOn() { return (data & 0b11); }

/* getter for Joker data */
uint8_t Joker::getData() { return data; }

/* setter for Joker Edition */
void Joker::setEdition(int edition) {
  set(MAX_3BIT, edition, EDITION_SHIFT, EDITION_MASK);
}

/* setter for Joker Rarity */
void Joker::setRarity(int rarity) {
  set(MAX_2BIT, rarity, RARITY_SHIFT, RARITY_MASK);
}

/* setter for Joker Activation Code */
void Joker::setActivateOn(int activation_code) {
  set(MAX_2BIT, activation_code, ACTIVATION_SHIFT, ACTIVATION_CODE_MASK);
}

/* setter for Description */
void Joker::setDescription(std::string text) { description = text; }

/* setter for Joker Name */
void Joker::setName(std::string value) { name = value; }

/* Find the type of filter that will be applied to the card selection:
   -1 for error,
   0 for no filter,
   1 for value type filter,
   2 for Suit type filter,
   3 for rank type filter
  */
int Joker::getFilterType() {
  int filter;
  switch (effect.filter) {
  case Filter::NONE:
    return filter = 0;
  case Filter::EVEN:
  case Filter::ODD:
    return filter = 1;
  case Filter::HEARTS:
  case Filter::CLUBS:
  case Filter::SPADES:
  case Filter::DIAMONDS:
    return filter = 2;
  case Filter::FACE:
  case Filter::ACE:
    return filter = 3;
  }
  return -1;
}
// something
/* Taking into consideration the filter type from the getFilterType method we
   evaluate the condition and return true if it is to be accepted */
bool Joker::evaluateFilter(PlayingCard *card, int type) {
  Filter filter = effect.filter;
  switch (type) {
  case 0:
    return true;
  case 1:
    if (filter == Filter::EVEN) {
      return static_cast<int>(card->getRank()) % 2 == 0;
    }
  }
  return true;
}

/* Use the Effect stuct to operate upon the rest of the values */
void Joker::operate(PlayingCard *card, int &money, Points &points, Deck &deck) {

  std::unordered_map<Target, int *> targetMap = {
      {Target::CHIPS, &points.chips},
      {Target::MULTIPLIER, &points.multiplier},
      {Target::MONEY, &money}};
  int &value = *targetMap[effect.target];
  int filter = getFilterType();
  func = operationMap[effect.operation];
  Target target = effect.target;
}

/* toString implementation for Joker object */
void Joker::toString() {
  std::cout << "Joker [Activation Code: " << getActivatedOn()
            << ", Rarity: " << getRarity() << ", Edition: " << getEdition()
            << ", Data: " << static_cast<int>(data)
            << ", Description: " << getDescription() << "]\n";
}
