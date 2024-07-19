#ifndef HAND_H
#define HAND_H

#include "handTypes.h"
#include <utility>
#include "points.h"
#include "playingCard.h"

class Hand {
  private:
    bool isHighCard() const;
    bool isPair();  const 
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
  public:
    std::pair<HandType, Points> evaluate();
    Hand(const std::array<PlayingCard, 5>& cards, int multiplier = 1, int chips = 0);
    void print() const;
};



#endif // !HAND_H
