#ifndef HAND_H
#define HAND_H

#include "deck.h"
#include "draw.h"
#include "handTypes.h"
#include "jokerDeck.h"
#include "playingCard.h"
#include "points.h"
#include <array>
#include <utility>
#include <vector>

class Hand {
private:
  Points points;
  std::array<PlayingCard, 5> cards;
  std::pair<int, int> pairTypes;
  std::vector<bool> positions;
  bool isHighCard() const;
  bool isPair() const;
  bool isTwoPair() const;
  bool isThreeOfAKind() const;
  bool isFourOfAKind() const;
  bool isFiveOfAKind() const;
  bool isFullHouse() const;
  bool isFlush() const;
  bool isStraight() const;
  bool isStraightFlush() const;
  bool isRoyalFlush() const;
  bool isFlushHouse() const;
  bool isFlushFive() const;
  bool isHighStraight() const;
  void findPairs();
  void setTrueVector();
  void scoreJokers(Deck &deck, int &money, JokerDeck &jdeck, int ON_TYPE);
  void scoreCards(Deck &deck, Draw &draw, int &money, JokerDeck &jdeck);
  void findRankOccurences(int (&ranks)[13], int cardCount);
  void findCommonPairs(std::pair<int, int> &pairCount, int (&ranks)[13]);
  void scoreCard(Deck &deck, JokerDeck &jdeck, Draw &draw, int &money,
                 PlayingCard card, int index, bool repeat);
  std::vector<bool> determinePositions(std::pair<int, int> &pairCount,
                                       int cardCount, int (&ranks)[13]);

public:
  Hand(const std::array<PlayingCard, 5> &cards, int multiplier, int chips);
  std::array<int, 5> toIntArray() const;

  void print() const;
  void printHandType(HandType type) const;

  std::vector<bool> getPositions() const;
  std::pair<int, int> getPairTypes() const;
  std::pair<HandType, Points> evaluate(Deck &deck, JokerDeck &jdeck, Draw &draw,
                                       int &money);
};

#endif // !HAND_H
