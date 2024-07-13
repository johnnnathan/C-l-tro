#ifndef DECK_H
#define DECK_H

#include "playingCard.h"

class Deck{
private:
  PlayingCard** deck ;
  int deckSize;
public:
  void addCard(PlayingCard* card);
  void removeCard(int cardID);
  void populateBoard();
  int getDeckSize();
  void alterDeckSize(int change);
  void toString();
  Deck(int size);
  ~Deck();
  PlayingCard* operator[](int index) const;


};

#endif 
