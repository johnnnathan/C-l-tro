#ifndef HAND_H
#define HAND_H

#include "handTypes.h"
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

public:
  Hand(const std::array<PlayingCard, 5> &cards, int multiplier, int chips);
  std::array<int, 5> toIntArray() const;

  void print() const;
  void printHandType(HandType type) const;

  std::vector<bool> getPositions() const;
  std::pair<int, int> getPairTypes() const;
  std::pair<HandType, Points> evaluate();
};

#endif // !HAND_H
