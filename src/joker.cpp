#include "joker.h"
#include "jokerEffectProperties.h"
#include "tools.h"
#include <cstdint>
#include <i386/limits.h>
#include <ostream>
#include <strstream>
#include <unordered_map>

/* Joker constructor */
Joker::Joker(int activation_code, int rarity, int edition, Effect effectTBA)
    : data(0), effect({Operation::ADD, Target::NONE, Filter::NONE, 0}) {
  data = 0;
  setRarity(rarity);
  setActivateOn(activation_code);
  setEdition(edition);
  setEffect(effectTBA);
}

Joker::Joker()
    : data(0), effect({Operation::ADD, Target::NONE, Filter::NONE, 0}) {

  // Randomly generate rarity, edition, and activation code
  int rarity = rand() % (MAX_2BIT + 1);
  int edition = rand() % (MAX_3BIT + 1);
  int activation_code = rand() % (MAX_2BIT + 1);

  // Set Joker attributes
  setRarity(rarity);
  setEdition(edition);
  setActivateOn(activation_code);

  // Name generation
  std::string name;

  switch (rarity) {
  case COMMON:
    name += "Mysterious ";
    break;
  case UNCOMMON:
    name += "Arcane ";
    break;
  case RARE:
    name += "Ethereal ";
    break;
  case LEGENDARY:
    name += "Mythic ";
    break;
  }

  switch (edition) {
  case NO_EDITION:
    name += "";
    break;
  case FOIL:
    name += "of the Gilded ";
    break;
  case HOLOGRAPHIC:
    name += "of the Phantasmal ";
    break;
  case POLYCHROME:
    name += "of the Prism ";
    break;
  case NEGATIVE:
    name += "of the Shadow ";
    break;
  }

  switch (activation_code) {
  case ON_PLAYED:
    name += "Harbinger";
    break;
  case ON_SCORED:
    name += "Guardian";
    break;
  case ON_HELD:
    name += "Warden";
    break;
  case ON_INDEPENDENT:
    name += "Wanderer";
    break;
  }

  setName(name);

  // Description generation
  std::string description = "This Joker is known as the " + name + ".";
  description += " Its powers are invoked ";
  switch (activation_code) {
  case ON_PLAYED:
    description += "when played.";
    break;
  case ON_SCORED:
    description += "when points are scored.";
    break;
  case ON_HELD:
    description += "when held in hand.";
    break;
  case ON_INDEPENDENT:
    description += "independently of other actions.";
    break;
  }
  setDescription(description);
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

void Joker::setEffect(Effect effectToBeAdded) { effect = effectToBeAdded; }

std::string Joker::getEffect() {
  std::ostrstream os;
  std::string operation = operationToString(effect.operation);
  std::string filter = filterToString(effect.filter);
  std::string target = targetToString(effect.target);
  int quan = effect.quantity;
  os << "Operation : " << operation << " Filter : " << filter
     << " Target : " << target << '\n';
  return os.str();
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
  std::unordered_map<Operation, std::function<void(int &, int)>> operationMap =
      {
          {Operation::ADD, add},
          {Operation::SUBTRACT, subtract},
          {Operation::MULTIPLY, multiply},
      };
  func = operationMap[effect.operation];
  Target target = effect.target;
}

/* toString implementation for Joker object */
void Joker::toString() {
  std::string rarity_str;
  switch (getRarity()) {
  case COMMON:
    rarity_str = "COMMON";
    break;
  case UNCOMMON:
    rarity_str = "UNCOMMON";
    break;
  case RARE:
    rarity_str = "RARE";
    break;
  case LEGENDARY:
    rarity_str = "LEGENDARY";
    break;
  }

  std::string activation_str;
  switch (getActivatedOn()) {
  case ON_PLAYED:
    activation_str = "ON_PLAYED";
    break;
  case ON_SCORED:
    activation_str = "ON_SCORED";
    break;
  case ON_HELD:
    activation_str = "ON_HELD";
    break;
  case ON_INDEPENDENT:
    activation_str = "ON_INDEPENDENT";
    break;
  }

  std::string edition_str;
  switch (getEdition()) {
  case NO_EDITION:
    edition_str = "NO_EDITION";
    break;
  case FOIL:
    edition_str = "FOIL";
    break;
  case HOLOGRAPHIC:
    edition_str = "HOLOGRAPHIC";
    break;
  case POLYCHROME:
    edition_str = "POLYCHROME";
    break;
  case NEGATIVE:
    edition_str = "NEGATIVE";
    break;
  }

  std::cout << getName() << " Activation Code: " << activation_str << " ("
            << getActivatedOn() << ")" << ", Rarity: " << rarity_str << " ("
            << getRarity() << ")" << ", Edition: " << edition_str << " ("
            << getEdition() << ")" << ", Data: " << static_cast<int>(data)
            << ", Description: " << getDescription()
            << ", Effect : " << getEffect() << "]\n";
}
