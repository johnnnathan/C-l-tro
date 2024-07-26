#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include "deck.h"
#include "playingCard.h"

class DiscardPile {
private:
  static const int MAX_SIZE = 52;
  PlayingCard *pile[MAX_SIZE];
  int size;
  int currentCards;

public:
  DiscardPile(int initialSize);
  void addCard(PlayingCard *card);
  void flush(Deck &deck);
  int getSize() const;
  int getCurrentCount() const;
  void toString() const;
};

#endif // DISCARDPILE_H
