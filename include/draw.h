#ifndef DRAW_H
#define DRAW_H

#include "discardPile.h"
#include "handTypes.h"
#include "playingCard.h"
#include "points.h"

const int DEFAULT_DRAW_SIZE = 8;

class Draw {
private:
  PlayingCard *drawPile[DEFAULT_DRAW_SIZE];

public:
  void toString();
  void discardCard(int ID, DiscardPile &pile, Deck &deck);
  void drawCard(Deck &deck);
  std::pair<HandType, Points> play(const std::array<PlayingCard, 5> &cards);
};

#endif // !DRAW_H
