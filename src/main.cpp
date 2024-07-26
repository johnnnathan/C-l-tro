#include "deck.h"
#include "discardPile.h"
#include "playingCard.h"
#include <iostream>

int main() {
  // Create a deck with a fixed size (for simplicity, using 5 cards)
  Deck deck(5);

  // Create some playing cards
  PlayingCard card1(1, 1, 0, 0, 0); // Example card
  PlayingCard card2(2, 1, 0, 0, 0); // Example card
  PlayingCard card3(3, 1, 0, 0, 0); // Example card

  // Add cards to the deck
  deck.addCard(&card1);
  deck.addCard(&card2);
  deck.addCard(&card3);
  deck.toString();

  // Create a discard pile with a fixed size (for simplicity, using 5 cards)
  DiscardPile discardPile(5);

  // Remove cards from the deck and add to discard pile
  discardPile.addCard(deck[5]); // Assuming `deck[0]` returns the card pointer
  deck.removeCard(0);

  discardPile.addCard(deck[5]); // Remove another card
  deck.removeCard(1);

  std::cout << '\n';
  deck.toString();
  std::cout << '\n';

  // Print the discard pile contents
  std::cout << "\nDiscard Pile Contents:\n";
  discardPile.toString(); // Assuming this prints all cards in the discard pile

  // Flush the discard pile back into the deck
  discardPile.flush(deck);

  // Print the deck contents after flushing
  std::cout << "\nDeck Contents after Flushing Discard Pile:\n";
  deck.toString(); // Assuming this prints all cards in the deck
}
