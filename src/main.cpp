#include "deck.h"
#include "discardPile.h" // Assuming this is correctly implemented
#include "draw.h"

int main() {
  // Create a deck with a fixed size (for simplicity, using 5 cards)
  Deck deck;

  deck.populateBoard();
  deck.shuffle();
  deck.toString();

  DiscardPile discardPile(52);
  Draw draw;
  draw.drawTillFull(deck);
  draw.toString();
  // something
}
