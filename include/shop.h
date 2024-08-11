#ifndef SHOP_H
#define SHOP_H

#include "cardProperties.h"
#include "joker.h"
#include "jokerDeck.h"
#include "playingCard.h"
#include <array>
#include <utility>

class Shop {
private:
  std::array<std::pair<PlayingCard *, int>, 3> cards;
  std::array<std::pair<Joker *, int>, 3> jokers;
  std::pair<Seal, int> seal;
  std::pair<Enhancement, int> enhancement;
  std::pair<Edition, int> edition;
  std::array<bool, 3> boughtJoker = {0, 0, 0};

  void setPlayingCards();
  void setJokers();
  void setSeal();
  void setEnhancement();
  void setEdition();
  std::tuple<char, char, int> getInput(bool &shouldExit);

  bool makeTransaction(int &money, int cost);

public:
  Shop();
  ~Shop();
  void set();
  void print();

  void buy(int &money, JokerDeck &jdeck, Deck &deck);
};

#endif // !SHOP_H
