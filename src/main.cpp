#include "deck.h"
#include "discardPile.h" // Assuming this is correctly implemented

int main() {
  // Create a deck with a fixed size (for simplicity, using 5 cards)
  Deck deck;

  deck.populateBoard();
  deck.shuffle();
  deck.toString();

  DiscardPile discardPile(52);

  while (deck.getDeckSize() > 5) {
  }

  return 0;
}
