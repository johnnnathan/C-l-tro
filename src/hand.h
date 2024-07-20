#ifndef HAND_H
#define HAND_H

#include "handTypes.h"
#include <array>
#include <utility>
#include <vector>
#include "points.h"
#include "playingCard.h"

class Hand {
  private:
    Points points;
    std::array<PlayingCard, 5> cards;
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
    std::pair<std::pair<int,int>, std::vector<bool>> findPairs();
  public:
    std::pair<HandType, Points> evaluate();
    Hand(const std::array<PlayingCard, 5>& cards, int multiplier, int chips);
    void print() const;
};

#endif // !HAND_H
