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
  Draw() {
    for (int i = 0; i < DEFAULT_DRAW_SIZE; i++) {
      drawPile[i] = nullptr;
    }
  }
  void toString();
  void discardCard(int ID, DiscardPile &pile, Deck &deck);
  void drawCard(Deck &deck);
  void drawTillFull(Deck &deck);
  void discardCards(std::array<int, 5> IDs, DiscardPile &pile, Deck &deck);
  std::pair<HandType, Points> play(const std::array<PlayingCard, 5> &cards,
                                   Deck &deck, int &money);
  PlayingCard *get(int x);
};

#endif // !DRAW_H
