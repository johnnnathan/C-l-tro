#include "discardPile.h"
#include <cassert>
#include <iostream>
#include <sstream>

// Constructor
DiscardPile::DiscardPile(int initialSize) : size(initialSize), currentCards(0) {
  // Ensure initialSize does not exceed the MAX_SIZE
  if (initialSize > MAX_SIZE) {
    size = MAX_SIZE;
  }
  for (int i = 0; i < size; ++i) {
    pile[i] = nullptr;
  }
}

// Add a card to the discard pile
void DiscardPile::addCard(PlayingCard *card) {
  assert(currentCards < size); // Ensure there's space to add the card
  pile[currentCards++] = card;
}

// Flush the discard pile into the deck
void DiscardPile::flush(Deck &deck) {
  for (int pileIndex = 0; pileIndex < currentCards; ++pileIndex) {
    if (pile[pileIndex] != nullptr) {
      deck.addCard(pile[pileIndex]);
      pile[pileIndex] = nullptr;
    }
  }
  currentCards = 0; // Reset the discard pile
}

// Get the size of the discard pile
int DiscardPile::getSize() { return size; }

// Get the current count of cards in the discard pile
int DiscardPile::getCurrentCount() { return currentCards; }

// Print the contents of the discard pile
void DiscardPile::toString() const {
  std::stringstream ss;
  for (int i = 0; i < currentCards; ++i) {
    ss << "Card " << i + 1 << ": " << pile[i]->toString() << "\n";
  }
  std::cout << ss.str();
}
