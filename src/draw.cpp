#include "draw.h"
#include "deck.h"
#include "discardPile.h"
#include "hand.h"
#include "handTypes.h"
#include "playingCard.h"
#include "tools.h"

std::string TOO_MANY_CARDS = "Too many cards in played hand, can not proceed";
std::string FULL_DRAW = "Hand is full, can not draw another card";
void Draw::toString() {
  std::cout << "Draw : " << std::endl;
  for (int i = 0; i < DEFAULT_DRAW_SIZE; i++) {
    if (drawPile[i] != nullptr) {
      std::cout << drawPile[i]->toString() << std::endl;
    }
  }
}
void Draw::discardCard(int ID, DiscardPile &pile, Deck &deck) {
  for (int i = 0; i < DEFAULT_DRAW_SIZE; i++) {
    if (drawPile[i] != nullptr && drawPile[i]->getID() == ID) {
      pile.addCard(drawPile[i], deck);
      drawPile[i] = nullptr;
    }
  }
}

void Draw::discardCards(std::array<int, 5> IDs, DiscardPile &pile, Deck &deck) {
  for (int i = 0; i < 5; i++) {
    discardCard(IDs[i], pile, deck);
  }
}

PlayingCard *Draw::get(int x) {
  if (!checkRange(DEFAULT_DRAW_SIZE, x)) {
    return nullptr;
  };
  return drawPile[x];
}
void Draw::drawCard(Deck &deck) {
  for (int i = 0; i < DEFAULT_DRAW_SIZE; i++) {
    if (drawPile[i] == nullptr) {
      drawPile[i] = deck.getCard();
      return;
    }
  }
  std::cout << FULL_DRAW << std::endl;
}
std::pair<HandType, Points> Draw::play(const std::array<PlayingCard, 5> &cards,
                                       JokerDeck jdeck, Deck &deck,
                                       int &money) {
  Draw draw = *this;
  Hand hand(cards, 0, 0);
  return hand.evaluate(deck, jdeck, draw, money);
}

void Draw::drawTillFull(Deck &deck) {
  for (int i = 0; i < DEFAULT_DRAW_SIZE; i++) {
    if (drawPile[i] == nullptr) {
      drawCard(deck);
    }
  }
}
