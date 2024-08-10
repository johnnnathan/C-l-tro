#ifndef SHOP_H
#define SHOP_H

#include "cardProperties.h"
#include "joker.h"
#include "playingCard.h"
class Shop {
private:
  std::array<std::pair<PlayingCard *, int>, 3> cards;
  std::array<std::pair<Joker, int>, 3> jokers;
  Seal seal;
  Enhancement enhancement;
  Edition edition;

  void setPlayingCards();
  void setJokers();
  void setSeal();
  void setEnhancement();
  void setEdition();

public:
  void set();
  void print();
};

#endif // !SHOP_H
