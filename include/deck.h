#ifndef DECK_H
#define DECK_H

#include "playingCard.h"
#include <vector>

class Deck {
private:
  std::vector<PlayingCard *> deck;
  int deckSize;

public:
  Deck();

  void addCard(PlayingCard *card);
  void removeCard(int cardID);
  void populateBoard();
  int getDeckSize();
  void alterDeckSize(int change);
  void toString();
  void shuffle();
  PlayingCard *operator[](int index) const;
};

#endif // DECK_H
