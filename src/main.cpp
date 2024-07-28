#include "deck.h"
#include "discardPile.h" // Assuming this is correctly implemented
#include "playingCard.h"
#include <iostream>

int main() {
  // Create a deck with a fixed size (for simplicity, using 5 cards)
  Deck deck;

  // Create some playing cards
  PlayingCard card1(1, 1, 1, 0, 0); // Example card
  PlayingCard card2(2, 1, 2, 0, 0); // Example card
  PlayingCard card3(3, 1, 3, 0, 0); // Example card

  // Add cards to the deck
  deck.addCard(&card1);
  deck.addCard(&card2);
  deck.addCard(&card3);

  // Print deck contents
  std::cout << "Deck contents:\n";
  deck.toString();

  // Create a discard pile with a fixed size (for simplicity, using 5 cards)
  DiscardPile discardPile(5);

  // Remove cards from the deck and add to discard pile
  discardPile.addCard(deck[0]); // Assuming `deck[0]` returns the card pointer
  deck.removeCard(0);

  discardPile.addCard(deck[0]); // Remove another card
  deck.removeCard(1);

  std::cout << "\nDeck contents after removing cards:\n";
  deck.toString();

  // Print the discard pile contents
  std::cout << "\nDiscard Pile Contents:\n";
  discardPile.toString(); // Assuming this prints all cards in the discard pile

  // Flush the discard pile back into the deck
  discardPile.flush(deck);

  // Print the deck contents after flushing
  std::cout << "\nDeck Contents after Flushing Discard Pile:\n";
  deck.toString();

  return 0;
}
