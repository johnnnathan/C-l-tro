#ifndef DECK_H
#define DECK_H

#include "playingCard.h"

class Deck{
private:
  playingCard** deck ;
  int deckSize;
public:
  void addCard(playingCard* card);
  void removeCard(int cardID);
  void populateBoard();
  int getDeckSize();
  void alterDeckSize(int change);
  Deck(int size);
  ~Deck();
  playingCard* operator[](int index) const;

};

#endif 
