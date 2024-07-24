#include "deck.h"
#include "playingCard.h"

int main() {
  // Create a deck with size 60
  Deck deck(12);

  // Add some custom cards
  PlayingCard *card1 = new PlayingCard(1, 1, 2, 1, 1);
  PlayingCard *card2 = new PlayingCard(2, 2, 3, 1, 2);
  deck.addCard(card1);
  deck.addCard(card2);
  std::cout << "\nDeck after adding custom cards:" << std::endl;
  deck.toString();

  // Remove one of the custom cards
  deck.removeCard(card1->getID());
  std::cout << "\nDeck after removing a custom card:" << std::endl;
  deck.toString();

  return 0;
}
