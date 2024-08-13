#include "jokerDeck.h"
#include "joker.h"
#include "tools.h"
#include <cstdio>
#include <iostream>

Joker *JokerDeck::get(int index) {
  if (index < getDeckSize() && jokers[index] != nullptr) {
    return jokers[index];
  }
  std::printf("Joker is null");
  return nullptr;
}

/* method to add Joker object to the JokerDeck object, implementation almost the
 * same as the playingCard deck's  */
void JokerDeck::addJoker(Joker *joker) {
  if (getJokerCount() >= getDeckSize()) {
    printError(FULL_JOKER_DECK);
    return;
  }
  for (int i = 0; i < getDeckSize(); i++) {
    if (jokers[i] == nullptr) {
      jokers[i] = joker;
      incrementCurrent();
      return;
    }
  }
  printError(ERROR_ADDING_JOKER);
}

/* method to remove Joker object from the JokerDeck obect, implementation almost
 * the same as the playingCard decks' */
void JokerDeck::removeJoker(std::string jokerName) {
  if (getJokerCount() == 0) {
    printError(EMPTY_JOKER_DECK);
    return;
  }
  for (int i = 0; i < getDeckSize(); i++) {
    if (jokers[i] != nullptr && jokers[i]->getName() == jokerName) {
      delete jokers[i];
      jokers[i] = nullptr;
      decrementCurrent();
      return;
    }
  }
  printError(JOKER_NOT_FOUND);
}

/* method to decrement the currentJokers variable */
void JokerDeck::decrementCurrent() { currentJokers -= 1; }

/* method to increment the currentJokers variable */
void JokerDeck::incrementCurrent() { currentJokers += 1; }

int JokerDeck::getDeckSize() { return deckSize; }
int JokerDeck::getJokerCount() { return currentJokers; }

/* prints the data of each Joker inside the jokerDeck by looping over all of the
 * entries inside the legal limit */
void JokerDeck::printDeck() {
  for (int i = 0; i < getDeckSize(); i++) {
    if (jokers[i] != nullptr) {
      jokers[i]->toString();
    } else {
      std::cout << "Empty Slot \n";
    }
  }
}
